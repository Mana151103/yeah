/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:03:35 by mosada            #+#    #+#             */
/*   Updated: 2023/12/27 19:28:10 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->here_doc = false;
	pipex->is_invalid_infile = false;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}

char	*check_args(t_pipex *pipex, int argc, char **argv)
{
	// if (!pipex->here_doc || pipex->is_invalid_infile)
	// 	return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->out_fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s\n", argv[argc - 1]);
		close(pipex->in_fd);
		exit(EXIT_FAILURE);
	}
	return ("OK");
}
