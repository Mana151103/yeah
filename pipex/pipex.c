/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:48:33 by mosada            #+#    #+#             */
/*   Updated: 2023/12/30 19:09:35 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_pipex *pipex, int k, int **pipes, int argc)
{
	char	**cmd;
	char	**paths;

	paths = find_cmds_in_path(pipex, argc);
	if (paths[k] == NULL)
	{
		ft_putstr_fd("zsh: command not found: ", STDERR_FILENO);
		ft_putendl_fd(pipex->cmd_args[k], STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (k != 0)
	{
		dup2(pipes[k - 1][0], STDIN_FILENO);
		close(pipes[k - 1][1]);
	}
	if (k != (argc - 4))
	{
		dup2(pipes[k][1], STDOUT_FILENO);
		close(pipes[k][0]);
	}
	cmd = ft_split(pipex->cmd_args[k], ' ');
	execve(paths[k], cmd, NULL);
	for (int i = 0; cmd[i] != NULL; i++)
		free(cmd[i]);
	for (int i = 0; paths[i] != NULL; i++)
		free(paths[i]);
	free(cmd);
	free(paths);
}

static int	pid_process(t_pipex *pipex, int argc, int **pipes, int k)
{
	pid_t	pid;

	if (k == 0)
		dup2(pipex->in_fd, STDIN_FILENO);
	if (k == (argc - 4))
		dup2(pipex->out_fd, STDOUT_FILENO);
	pid = fork();
	pipex->lastpid = pid;
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
		child(pipex, k, pipes, argc);
	else
	{
		if (k != (argc - 4))
		{
			close(pipes[k][1]);
			k++;
			pid_process(pipex, argc, pipes, k);
		}
	}
	return (0);
}

static void	generate_pipes(int **pipes, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 4))
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
		{
			while (i != -1)
			{
				free(pipes[i]);
				i--;
			}
			free(pipes);
			exit(EXIT_FAILURE);
		}
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	execution(t_pipex *pipex, int argc, int **pipes)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	pid_process(pipex, argc, pipes, k);
	while (k < (argc - 4))
	{
		free(pipes[k]);
		k++;
	}
	free(pipes);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		**pipes;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	init_pipex(pipex);
	if (ft_strncmp(check_args(pipex, argc, argv), "OK", 2) == 0)
	{
		pipex->cmd_args = ft_parse_args(pipex, argc, argv);
		pipex->cmd_paths = ft_parse_cmds(pipex, envp);
		pipes = (int **)malloc(sizeof(int *) * (argc - 4));
		if (!pipes)
			return (free(pipex), EXIT_FAILURE);
		generate_pipes(pipes, argc);
		execution(pipex, argc, pipes);
		ft_wait(pipex, argc);
		for (int i = 0; pipex->cmd_paths[i] != NULL; i++)
			free(pipex->cmd_paths[i]);
		for (int i = 0; pipex->cmd_args[i] != NULL; i++)
			free(pipex->cmd_args[i]);
		return (free(pipex->cmd_args), free(pipex->cmd_paths), free(pipex), 0);
	}
	else
		return (EXIT_FAILURE);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
