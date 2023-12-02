/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:22:30 by mosada            #+#    #+#             */
/*   Updated: 2023/11/30 16:22:24 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef	enum	e_bool
{
	false, //0
	true, //1
}	t_bool;

typedef	struct	s_pipex
{
	int		in_fd;
	int		out_fd;
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}	t_pipex;

void	initializepipex(t_pipex *pipex) //ft_init_pipex
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->here_doc = false;
	pipex->is_invalid_infile = false;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
}

char	*check_args(t_pipex *pipex, char **argv) //file open
{
	if (pipex->cmd_count != 5)
		return (NULL);
	if (!pipex->here_doc || pipex->is_invalid_infile)
		return (NULL);
	if (access(argv[1], O_RDONLY) == -1)
		return (NULL);
	if (access(argv[4], O_WRONLY) == -1)
		return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		return (NULL);
	pipex->out_fd = open(argv[4], O_WRONLY);
	if (pipex->in_fd == -1)
		return (NULL);
}

char	**ft_parse_cmds(t_pipex *pipex, char **envp) //make path array
{
	size_t	len;
	int		i;

	i = 0;
	while (envp[i])
	{
		pipex->cmd_paths[i] = get_path_from_buf(envp[i]);
		i++;
	}
	pipex->cmd_paths[i] = NULL;
	return (pipex->cmd_paths);
}

char	**ft_parse_args(t_pipex *pipex, char **argv) //make command array
{
	int		i;
	int		k;
	size_t	len;

	i = 0;
	while (i < 2)
	{
		k = 0;
		len = ft_strlen(argv[i]);
		pipex->cmd_args[i] = (char **)malloc(sizeof(char*) * (len + 1));
		if (!pipex->cmd_args)
			return (NULL);
		while (pipex->cmd_args[i])
		{
			pipex->cmd_args[i][k] = argv[i][k];
			k++;
		}
		i++;
	}
	pipex->cmd_args[i] = NULL;
	return (pipex->cmd_args);
}

void	ft_exec(t_pipex *pipex) //本体
{
	int		fd[2];
	pid_t	pid;
	char	**commands;
	char	**paths;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE); //probram finish
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (pid == 0) //child
	{
		commands = ft_parse_args(pipex, envp);
		paths = ft_parse_cmds(pipex, argv);
		dup2(pipex->in_fd, STDOUT_FILENO); //rewrite fd
		execve(paths, commands, NULL);
	}
	else
	{
	}
}

void	ft_cleanup(t_pipex pipex)
{
	close();
	close();
}
