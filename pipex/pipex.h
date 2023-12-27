/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:06:15 by mosada            #+#    #+#             */
/*   Updated: 2023/12/27 18:37:34 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	**cmd_args;
}	t_pipex;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_printf(const char *fmt, ...);
int		get_path_index(char **envp);
char	**get_path_from_buf(char *buf);
void	init_pipex(t_pipex *pipex);
char	*check_args(t_pipex *pipex, int argc, char **argv);
char	**ft_parse_cmds(t_pipex *pipex, char **envp);
char	**ft_parse_args(t_pipex *pipex, int argc, char **argv);
char	**find_cmds_in_path(t_pipex *pipex, int argc);

#endif
