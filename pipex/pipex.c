/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:22:30 by mosada            #+#    #+#             */
/*   Updated: 2023/12/02 20:55:54 by mosada           ###   ########.fr       */
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
	char	***cmd_args;
	int		cmd_count;
}	t_pipex;

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->here_doc = false;
	pipex->is_invalid_infile = false;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
}

char	*check_args(t_pipex *pipex, char **argv)	//file open
{
	if (pipex->cmd_count != 5)
		return (NULL);
	if (!pipex->here_doc || pipex->is_invalid_infile)
		return (NULL);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
		return (NULL);
	pipex->out_fd = open(argv[4], O_WRONLY);
	if (pipex->in_fd == -1)
		return (NULL);
	return ("ok");
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

char	***ft_parse_args(t_pipex *pipex, int argc, char ***argv)	//make command array
{
	int		i;
	int		k;
	int		j;
	int		n;
	size_t	len;

	i = 2;
	pipex->cmd_args = malloc(sizeof(char **) * (argc - 2));
	if (!pipex->cmd_args)
		return (NULL);
	while (i < (argc - 1))
	{
		k = 0;
		printf("argv[2] = %s\n", *argv[i]);
		n = count_words(*argv[i], ' ');
		printf("n = %d\n", n);
		pipex->cmd_args[i] = malloc(sizeof(char *) * (n + 1));
		//if (!pipex->cmd_args[i])
		//{
		//	while (k < i)
		//	{
		//		free(pipex->cmd_args[k]);
		//		k++;
		//	}
		//	return (NULL);
		//}
		while (k < n)
		{
			len = ft_strlen(argv[i][k]);
			printf("len = %zu\n", len);
			pipex->cmd_args[i][k] = malloc(sizeof(char) * (len + 1));
			//if (!pipex->cmd_args[i][k])
			//{
			//	while (i > -1)
			//	{
			//		j = 0;
			//		while (j < k)
			//		{
			//			free(pipex->cmd_args[i][k]);
			//			j++;
			//		}
			//		free(pipex->cmd_args[i]);
			//		i--;
			//	}
			//	free(pipex->cmd_args);
			//	return (NULL);
			//}
			strcpy(pipex->cmd_args[i][k], argv[i][k]);
			printf("cmd_args = %s\n", pipex->cmd_args[i][k]);
			k++;
		}
		pipex->cmd_args[i][k] = NULL;
		i++;
	}
	pipex->cmd_args[i] = NULL;
	return (pipex->cmd_args);
}

//void	ft_exec(t_pipex *pipex)
//{
//	int		fd[2];
//	pid_t	pid;
//	char	**commands;
//	char	**paths;

//	if (pipe(fd) == -1)
//	{
//		perror("pipe");
//		exit(EXIT_FAILURE);	//probram finish
//	}
//	pid = fork();
//	if (pid == -1)
//	{
//		perror("fork");
//		return (EXIT_FAILURE);
//	}
//	if (pid == 0)	//child
//	{
//		commands = ft_parse_args(pipex, envp);
//		paths = ft_parse_cmds(pipex, argv);
//		dup2(pipex->in_fd, STDOUT_FILENO);	//rewrite fd
//		execve(paths, commands, NULL);
//	}
//	else
//	{
//	}
//}

//void	ft_cleanup(t_pipex pipex)
//{
//	close();
//	close();
//}

int main(int argc, char **argv) {
    t_pipex pipex;

    // 引数の配列を取得
    pipex.cmd_args = ft_parse_args(&pipex, argc, &argv);

    // 取得した引数の配列を表示
    printf("Command arguments array:\n");
    for (int i = 0; i < argc - 3; i++) {
        printf("Command %d arguments:\n", i);
        for (int k = 0; pipex.cmd_args[i][k] != NULL; k++) {
            printf("    %s\n", pipex.cmd_args[i][k]);
        }
    }

    // メモリ解放
    for (int i = 0; i < argc - 3; i++) {
        for (int k = 0; pipex.cmd_args[i][k] != NULL; k++) {
            free(pipex.cmd_args[i][k]);
        }
        free(pipex.cmd_args[i]);
    }
    free(pipex.cmd_args);

    return 0;
}