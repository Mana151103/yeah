#include <stdio.h>
int	main(void)
{
	int	c = 54;
	char *null_str = NULL;
	int	result = ft_printf("%5chis paragraph is indented", 't');
	puts("");
	printf("%5chis paragraph is indented", 't');
	puts("");
	return 0;
}