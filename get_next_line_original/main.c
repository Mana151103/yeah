#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main(void)
{
	char	*c;
	int fd = open("sample.txt",O_RDONLY);

	c = get_next_line(fd);
	while (*c)
	{
		printf("%s\n",c);
		free (c);
	}
	close(fd);
	return 0;
}
