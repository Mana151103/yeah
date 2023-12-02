/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:40 by mosada            #+#    #+#             */
/*   Updated: 2023/12/02 16:30:22 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

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

//int	main(int argc, char **argv, char **envp)
//{
//    int pathIndex = get_path_index(envp);

//    if (pathIndex == -1) {
//        fprintf(stderr, "PATH not found in environment variables.\n");
//        return 1;
//    }

//    // PATHが格納された文字列を取得
//    char **path = get_path_from_buf(envp[pathIndex]);

//    // 各パスを表示
//    printf("PATH contains the following directories:\n");
//    for (int i = 0; path[i] != NULL; i++) {
//        printf("%s\n", path[i]);
//        free(path[i]); // ft_splitで割り当てたメモリを解放
//    }

//    free(path); // pathの配列自体のメモリを解放

//    return 0;
//}

//> ./a.out
//PATH contains the following directories:
///Library/Frameworks/Python.framework/Versions/3.9/bin
///usr/local/bin
///usr/bin
///bin
///usr/sbin
///sbin
///usr/local/go/bin
///usr/local/munki
///opt/X11/bin
