/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:48:33 by mosada            #+#    #+#             */
/*   Updated: 2023/12/26 20:52:32 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_pipex *pipex, int k, int **pipes, int argc)
{
	char	**cmd;
	char	**paths;

	paths = find_cmds_in_path(pipex, argc);
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
}

static int	pid_process(t_pipex *pipex, int argc, int k, int **pipes)
{
	pid_t	pid;

	if (k == 0)
		dup2(pipex->in_fd, STDIN_FILENO);
	if (k == (argc - 4))
		dup2(pipex->out_fd, STDOUT_FILENO);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0)
		child(pipex, k, pipes, argc);
	else
	{
		waitpid(pid, NULL, 0);
		if (k != (argc - 4))
			close(pipes[k][1]);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;
	int		k;
	int		**pipes;

	i = 0;
	k = 0;
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	init_pipex(pipex);
	if (ft_strncmp(check_args(pipex, argc, argv), "OK", 2) == 0)
	{
		pipex->cmd_args = ft_parse_args(pipex, argc, argv);
		pipex->cmd_paths = ft_parse_cmds(pipex, envp);
		pipes = (int **)malloc((argc - 4) * sizeof(int *));
		while (i < (argc - 4))
		{
			pipes[i] = (int *)malloc(2 * sizeof(int));
			if (pipe(pipes[i]) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		while (k < (argc - 3))
		{
			pid_process(pipex, argc, k, pipes);
			k++;
		}
		while (i < (argc - 4))
			free(pipes[i++]);
		return (free(pipes), free(pipex->cmd_args), free(pipex->cmd_paths), 0);
	}
	else
		return (EXIT_FAILURE);
}
