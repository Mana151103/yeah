/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:40 by mosada            #+#    #+#             */
/*   Updated: 2023/12/26 17:04:44 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_path_index(char **envp)
{
	int	is_path;
	int	envc;

	envc = 0;
	while (*envp)
	{
		is_path = ft_strncmp(*envp, "PATH=", 5);
		if (!is_path)
			return (envc);
		envp++;
		envc++;
	}
	return (0);
}

char	**get_path_from_buf(char *buf)
{
	char	**path;

	buf += 5;	//rm "PATH="
	path = ft_split(buf, ':');
	return (path);
}
