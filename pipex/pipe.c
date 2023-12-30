/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:22:30 by mosada            #+#    #+#             */
/*   Updated: 2023/12/30 19:00:04 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_parse_cmds(t_pipex *pipex, char **envp)
{
	int		n;
	int		i;
	int		p_i;
	char	**paths;

	i = 0;
	n = 0;
	p_i = get_path_index(envp);
	paths = get_path_from_buf(envp[p_i]);
	while (paths[i])
	{
		i++;
		n++;
	}
	i = 0;
	pipex->cmd_paths = malloc(sizeof(char *) * (n + 1));
	if (!pipex->cmd_paths)
		return (NULL);
	while (paths[i] != NULL)
	{
		pipex->cmd_paths[i] = paths[i];
		free(paths[i]);
		i++;
	}
	pipex->cmd_paths[i] = NULL;
	return (free(paths), pipex->cmd_paths);
}

char	**ft_parse_args(t_pipex *pipex, int argc, char **argv)
{
	int		i;

	i = 2;
	pipex->cmd_args = malloc(sizeof(char *) * (argc - 2));
	if (!pipex->cmd_args)
		return (NULL);
	while (i < argc)
	{
		pipex->cmd_args[i - 2] = malloc(ft_strlen(argv[i]) + 1);
		if (!pipex->cmd_args[i - 2])
		{
			while (i != 2)
			{
				free(pipex->cmd_args[i - 2]);
				i--;
			}
			return (free(pipex->cmd_args), NULL);
		}
		if (i < (argc - 1))
			ft_strlcpy(pipex->cmd_args[i - 2], argv[i], ft_strlen(argv[i]) + 1);
		else
			pipex->cmd_args[i - 2] = NULL;
		i++;
	}
	return (pipex->cmd_args);
}

static char	*process_cmd_path(t_pipex *pipex, char **cmd, int i)
{
	char	*path;
	char	*new_path;
	char	*new_path2;

	new_path = ft_strjoin(pipex->cmd_paths[i], "/");
	if (!new_path)
		return (NULL);
	new_path2 = ft_strjoin(new_path, cmd[0]);
	free(new_path);
	if (!new_path2)
		return (NULL);
	path = malloc(ft_strlen(new_path2) + 1);
	if (!path)
		return (free(new_path2), NULL);
	ft_strlcpy(path, new_path2, ft_strlen(new_path2) + 1);
	free(new_path2);
	if (access(path, X_OK) == 0)
		return (path);
	else
		return (free(path), cmd[0]);
}

static char	*make_result(t_pipex *pipex, int k)
{
	char	**cmd;
	char	*c_path;
	int		i;

	i = 0;
	while (pipex->cmd_paths[i])
	{
		cmd = ft_split(pipex->cmd_args[k], ' ');
		c_path = process_cmd_path(pipex, cmd, i);
		if (access(c_path, X_OK) == 0)
			return (c_path);
		i++;
	}
	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	return (c_path);
}

char	**find_cmds_in_path(t_pipex *pipex, int argc)
{
	char	**result;
	int		j;
	int		k;

	j = 0;
	k = 0;
	result = malloc(sizeof(char *) * (argc - 1));
	if (!result)
		return (NULL);
	while (k < (argc - 3))
	{
		result[j] = make_result(pipex, k);
		if (access(result[j], X_OK) != 0)
			result[j] = NULL;
		j++;
		k++;
	}
	result[j] = NULL;
	return (result);
}
