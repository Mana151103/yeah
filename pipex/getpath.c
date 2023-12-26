/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:44:40 by mosada            #+#    #+#             */
/*   Updated: 2023/12/26 15:55:58 by mosada           ###   ########.fr       */
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

// int main(int argc, char **argv, char **envp) {
//     int pathIndex = get_path_index(envp);

//     if (pathIndex == -1) {
//         fprintf(stderr, "PATH 環境変数が見つかりませんでした。\n");
//         return 1;
//     }

//     // PATH からディレクトリの配列を取得
//     char **path = get_path_from_buf(envp[pathIndex]);

//     // ディレクトリ内で ls のパスを検索
//     char *lsPath = find_ls_in_path(path);

//     if (lsPath != NULL) {
//         printf("ls のパス: %s\n", lsPath);
//         free(lsPath); // lsPath で確保したメモリを解放
//     } else {
//         printf("PATH 内で ls が見つかりませんでした。\n");
//     }

//     // path 配列で確保したメモリを解放
//     for (int i = 0; path[i] != NULL; i++) {
//         free(path[i]);
//     }
//     free(path);

//     return 0;
// }

// int	main(int argc, char **argv, char **envp)
// {
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
// }

// ❯ ./a.out                              
// PATH contains the following directories:
// /opt/homebrew/bin
// /opt/homebrew/sbin
// /usr/local/bin
// /System/Cryptexes/App/usr/bin
// /usr/bin
// /bin
// /usr/sbin
// /sbin
// /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin
// /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin
// /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin
// /Library/Apple/usr/bin
