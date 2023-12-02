// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[], char *envp[])
// {
//     int i = 0;

//     /*  argc の確認 */
//     printf("argc = %d\n", argc);

//     /* argv の確認 */
//     printf("argv = [");
//     for (i = 0; i < argc; i++)
//     {
//         printf("\'%s\' ", argv[i]);
//     }
//     printf("]\n");

//     /* envp の確認 */
//     printf("envp = [");
//     for (i = 0; envp[i]; i++)
//     {
//         printf("\'%s\' ", envp[i]);
//     }
//     printf("]\n");

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     // PATH環境変数の値を取得
//     char *path_env = getenv("PATH");

//     if (path_env != NULL) {
//         // PATHをコピーしてトークン分割
//         char *path_copy = strdup(path_env);
//         char *token = strtok(path_copy, ":");

//         // 各パスを表示
//         while (token != NULL) {
//             printf("%s\n", token);
//             token = strtok(NULL, ":");
//         }

//         // メモリの解放
//         free(path_copy);
//     } else {
//         printf("PATH environment variable not found.\n");
//     }

//     return 0;
// }

