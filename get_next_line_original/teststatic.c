#include <stdio.h>

int	test_counter(void)
{
	static int	cnt;
	return (cnt++);
}

void	test_static1(void)
{
	for (int i = 0;i < 10; i++)
		printf("counter%d: %d\n",i, test_counter());
}

void	test_static2(void)
{
	for (int i = 0;i < 10; i++)
		printf("counter%d: %d\n",i, test_counter());
}

int	main(void)
{
	test_static1();
	test_static2();
	return 0;
}
