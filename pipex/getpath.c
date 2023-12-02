/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:40 by mosada            #+#    #+#             */
/*   Updated: 2023/11/29 14:37:27 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_path_index(char **envp)
{
	int	is_path;
	int	envc;

	envc = 0;
	while (*envp)
	{
		is_path = ft_strncmp(envp, "PATH=", 5);
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

	buf += 5; //rm "PATH="
	path = ft_split(buf, ":");
	return (path);
}
