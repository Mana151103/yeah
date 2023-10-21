#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd);

int main(void)
{
    //int fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
    int fd = open("sample1.txt", O_RDONLY);
    //int fd = -1;
    //int fd = OPEN_MAX;
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
	puts("");
    close(fd);
    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}