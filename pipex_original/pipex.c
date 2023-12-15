/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:22:30 by mosada            #+#    #+#             */
/*   Updated: 2023/12/15 18:24:01 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int		get_path_index(char **envp);
char	**get_path_from_buf(char *buf);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

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

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->here_doc = false;
	pipex->is_invalid_infile = false;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}

char	*check_args(t_pipex *pipex, int argc, char **argv)	//file open
{
	// if (!pipex->here_doc || pipex->is_invalid_infile)
	// 	return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		return (NULL);
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex->out_fd == -1)
		return (NULL);
	return ("OK");
}

char	**ft_parse_cmds(t_pipex *pipex, char **envp)	//make path array
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
		i++;
	}
	pipex->cmd_paths[i] = NULL;
	return (pipex->cmd_paths);
}

int	count_words(char *s, char c)
{
	int	flag;
	int	count;
	int	i;

	flag = 1;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		if (flag == 1 && (s[i] != c))
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

char	**ft_parse_args(t_pipex *pipex, int argc, char **argv) //make cmd array
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

char	*process_cmd_path(t_pipex *pipex, char **cmd, int i)
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
	ft_strlcpy(path, new_path2, ft_strlen(new_path2) + 1); //make new path
	free(new_path2);
	if (access(path, X_OK) == 0)
		return (path);
	else
		return (free(path), NULL);
}

char	*make_result(t_pipex *pipex, int k)
{
	char	**cmd;
	char	*c_path;
	int		i;

	i = 0;
	while (pipex->cmd_paths[i])
	{
		cmd = ft_split(pipex->cmd_args[k], ' ');
		c_path = process_cmd_path(pipex, cmd, i);
		if (c_path != NULL)
			return (c_path);
		i++;
	}
	return (NULL);
}

char	**find_cmds_in_path(t_pipex *pipex, int argc) //make using math array
{
	char	**cmd;
	char	**result;
	int		i;
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
		j++;
		k++;
	}
	result[j] = NULL;
	return (result);
}

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
		//for (int j = 0; pipex->cmd_args[j] != NULL; j++)
		//	printf("cmd->args[%d] = %s\n", j, pipex->cmd_args[j]);
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
