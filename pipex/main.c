/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:48:33 by mosada            #+#    #+#             */
/*   Updated: 2023/12/26 17:16:50 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;
	int		i;
	int		k;
	int		fd[2];
	pid_t	pid;
	char	**paths;
	char	**cmd;

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
		paths = find_cmds_in_path(pipex, argc);
		if (pipe(fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);	//program finish
		}
		for (k = 0; k < 2; ++k)
		{
			if (k == 0)
				dup2(pipex->in_fd, STDIN_FILENO); // First command, redirect infile to stdin
			if (k == 1)
				dup2(pipex->out_fd, STDOUT_FILENO);
			pid = fork();
			if (pid < 0)
			{
				perror("fork");
				return (EXIT_FAILURE);
			}
			if (pid == 0)	//child process
			{
				dup2(pipex->in_fd, STDIN_FILENO);
				cmd = ft_split(pipex->cmd_args[k], ' ');
				dup2(fd[1], STDOUT_FILENO);	//rewrite fd
				close(fd[0]); //end of pipe
				execve(paths[k], cmd, NULL);
			}
			else //parent process
			{
				waitpid(pid, NULL, 0);
				cmd = ft_split(pipex->cmd_args[k + 1], ' ');
				//dup2(fd[0], STDIN_FILENO);
				close(fd[1]); // close the write end of the pipe
        		if (k < 1)
					pipex->in_fd = fd[0];
				else
					close(fd[0]);
        	}
		}
		close(pipex->out_fd);
		free(pipex->cmd_args);
		free(pipex->cmd_paths);
		return (0);
	}
	else
		return (EXIT_FAILURE);
}
