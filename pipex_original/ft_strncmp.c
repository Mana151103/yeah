#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*r1;
	unsigned char	*r2;

	r1 = (unsigned char *)s1;
	r2 = (unsigned char *)s2;
	while (n--)
	{
		if (*r1 != *r2 || !*r1 || !*r2)
			return (*r1 - *r2);
		r1++;
		r2++;
	}
	return (0);
}