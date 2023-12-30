/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:03:35 by mosada            #+#    #+#             */
/*   Updated: 2023/12/30 18:09:56 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	//pipex->here_doc = false;
	pipex->is_invalid_infile = false;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->lastpid = 0;
}

char	*check_args(t_pipex *pipex, int argc, char **argv)
{
	// if (!pipex->here_doc || pipex->is_invalid_infile)
	// 	return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(argv[1], STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->out_fd == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(argv[argc - 1], STDERR_FILENO);
		close(pipex->in_fd);
		exit(EXIT_FAILURE);
	}
	return ("OK");
}

int	ft_wait(t_pipex *pipex, int argc)
{
	int	exit_status;
	int	status;
	int	i;

	i = 0;
	while (i < (argc - 3))
	{
		if (wait(&status) == pipex->lastpid)
			exit_status = WEXITSTATUS(status);
		i++;
	}
	return (exit_status);
}
