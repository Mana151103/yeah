/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:22:30 by mosada            #+#    #+#             */
/*   Updated: 2023/12/08 21:26:52 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		get_path_index(char **envp);
char	**get_path_from_buf(char *buf);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);

typedef enum e_bool
{
	false,	//0
	true,	//1
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
	if (!pipex->here_doc || pipex->is_invalid_infile)
		return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		return (NULL);
	pipex->out_fd = open(argv[argc - 1], O_WRONLY);
	if (pipex->in_fd == -1)
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

char	**ft_parse_args(t_pipex *pipex, int argc, char **argv) //make path array
{
	int		i;
	size_t	len;

	i = 2;
	pipex->cmd_args = malloc(sizeof(char *) * (argc - 1));
	if (!pipex->cmd_args)
		return (NULL);
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		pipex->cmd_args[i - 2] = malloc(sizeof(char) * (len + 1));
		if (!pipex->cmd_args[i - 2])
		{
			while (i != 2)
			{
				free(pipex->cmd_args[i - 2]);
				i--;
			}
			return (free(pipex->cmd_args), NULL);
		}
		ft_strlcpy(pipex->cmd_args[i - 2], argv[i], len + 1);
		i++;
	}
	pipex->cmd_args[i - 2] = NULL;
	return (pipex->cmd_args);
}

char	*process_cmd_path(t_pipex *pipex, char **cmd, int i)
{
	char	*path;
	char	*new_path;
	char	*new_path2;

	path = malloc(ft_strlen(pipex->cmd_paths[i]) + ft_strlen(cmd[0]) + 2); // "/ + cmd + 1"
	if (!path)
		return (NULL);
	new_path = ft_strjoin(pipex->cmd_paths[i], "/");
	new_path2 = ft_strjoin(new_path, cmd[0]);
	ft_strlcpy(path, new_path2, ft_strlen(new_path2) + 1); //make new path
	free(new_path);
	free(new_path2);
	if (access(path, X_OK) == 0)
		return (path);
	else
		return (free(path), NULL);
}

char	**find_cmds_in_path(t_pipex *pipex, int argc)
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
	while (k < (argc - 2))
	{
		i = 0;
		while (pipex->cmd_paths[i])
		{
			cmd = ft_split(pipex->cmd_args[k], ' ');
			result[j] = process_cmd_path(pipex, cmd, i);
			if (result[j] != NULL)
			{
				j++;
				break ;
			}
			i++;
		}
		k++;
	}
	result[j] = NULL;
	return (result);
}

// int	ft_exec(t_pipex *pipex, int argc, char **argv, char **envp)
// {
// 	int		i;
// 	int		fd[2];
// 	pid_t	pid;

// 	i = 0;
// 	// fd[0] = pipex->in_fd;
// 	// fd[1] = pipex->out_fd;
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);	//probram finish
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		return (EXIT_FAILURE);
// 	}
// 	if (pid == 0)	//child process
// 	{
// 		close(fd[0]);
// 		pipex->cmd_args = ft_parse_args(pipex, argc, argv);
// 		pipex->cmd_paths = ft_parse_cmds(pipex, envp);
// 		dup2(fd[1], STDOUT_FILENO);	//rewrite fd
// 		// while(i < (argc - 3))
// 		execve(pipex->cmd_paths[0], pipex->cmd_args, NULL);
// 		perror("execve");
// 		exit(EXIT_FAILURE);
// 	}
// 	else //parent process
// 	{
// 		close(fd[1]); // close the write end of the pipe
// 		dup2(fd[0], STDIN_FILENO);
// 		// Open the output file
//         int outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
//         if (outfile_fd == -1) {
//             perror("open");
//             exit(EXIT_FAILURE);
//         }

//         // Redirect stdout to the output file
//         dup2(outfile_fd, STDOUT_FILENO);

//         // Read from the read end of the pipe and write to the output file
//         char buffer[4096];
//         ssize_t bytesRead;

//         while ((bytesRead = read(fd[0], buffer, sizeof(buffer))) > 0)
//         {
//             write(STDOUT_FILENO, buffer, bytesRead);
//         }

//         // Close file descriptors
//         close(outfile_fd);
//         close(fd[0]);

//         // Wait for the child process to finish
// 		wait(NULL);
// 	}
// 	return (0);
// }

//void	ft_cleanup(t_pipex pipex)
//{
//	close();
//	close();
//}

// int main(int argc, char **argv, char **envp) {
//     t_pipex pipex;

//     // 引数の検証
//     if (argc != 5) {
//         fprintf(stderr, "Usage: %s infile \"ls -la\" \"wc -l\" outfile\n", argv[0]);
//         return 1;
//     }

//     // パイプを使用してコマンドを実行
//     ft_exec(&pipex, argc, argv, envp);

//     return 0;
// }

int main(int argc, char **argv, char **envp) //check find_cmds_in_path
{
	char	**cmd_paths;
	char	**cmd_args;
	char	**cmd_path;
	t_pipex	pipex;
    init_pipex(&pipex);

	cmd_paths = ft_parse_cmds(&pipex, envp);
	if (cmd_paths == NULL)
	{
        fprintf(stderr, "Error: Unable to parse command paths.\n");
        return 1;
	}
	//for (int i = 0; cmd_paths[i] != NULL; i++)
	//	printf("cmd_paths[%d] = %s\n", i, cmd_paths[i]);
	cmd_args = ft_parse_args(&pipex, argc, argv);
	if (cmd_args == NULL)
	{
        fprintf(stderr, "Error: Unable to parse command arguments.\n");
        return 1;
	}
	cmd_path = find_cmds_in_path(&pipex, argc);
	if (cmd_path != NULL)
	{
		for (int i = 0; cmd_path[i] != NULL; i++)
			printf("cmd_path[%d] = %s\n", i, cmd_path[i]);
	}
	else
		printf("Command not found in PATH\n");
	for (int i = 0; cmd_paths[i] != NULL; i++)
		free(cmd_paths[i]);
	free(cmd_paths);
	for (int i = 0; cmd_args[i] != NULL; i++)
    	free(cmd_args[i]);
	free(cmd_args);
	return 0;
}