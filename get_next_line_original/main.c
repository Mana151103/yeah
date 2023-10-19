#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
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