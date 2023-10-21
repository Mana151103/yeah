#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd);

int main(void)
{
    int fd1 = open("sample1.txt", O_RDONLY);
    int fd2 = open("sample2.txt", O_RDONLY);
    int fd3 = open("sample3.txt", O_RDONLY);
	//int	fd = -4;
	//int	fd = INT_MAX;
    char *line;
	int	count = 0;

	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			count++;
		printf("line1 = %s\n",line);
		free(line);
		line = get_next_line(fd2);
		if (!line)
			count++;
		printf("line2 = %s\n",line);
		free(line);
		line = get_next_line(fd3);
		if (!line)
			count++;
		printf("line3 = %s\n",line);
		free(line);
		if (count == 3)
			break;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	puts("");
	return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}