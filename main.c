/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:21:36 by mosada            #+#    #+#             */
/*   Updated: 2023/09/28 08:50:34y mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

//void	check_strnstr(void)
//{
//	char	*a1 = ft_strnstr(str, "", i);
//	char	*a2 = strnstr(str, "", i);
//	printf("%p\n",a1);
//	printf("%p\n",a2);
//}

void	check_strlcpy(void)
{
	char	d1[10] = {1,1,1,1,1,1,1,1,1,1};
	char	d2[10] = {1,1,1,1,1,1,1,1,1,1};
	const char	s1[] = "sleepy";
	for (int t = 0; t < 10; t++)
	{
		strlcpy(d1,s1,t);
		for (int i = 0; i < 10; i++)
			printf("%d,",d1[i]);
		puts("");	
		ft_strlcpy(d2,s1,t);
		for (int i = 0; i < 10; i++)
			printf("%d,",d2[i]);
		puts("\n=====================");
	}
}

//void	check_strlcat(void)
//{
	//char	d1[15] = {'a', 'a', 'a', 'a', 'a', '\0', 1, 1, 1, 1, 1, 1, 1, 1, 1};
	//char	d2[15] = {'a', 'a', 'a', 'a', 'a', '\0', 1, 1, 1, 1, 1, 1, 1, 1, 1};
	//const char	s1[] = "123";
//	char *src1 = calloc(100, sizeof(char));
//	ft_strlcat(NULL, src1, 0)
//	for (int t = 0; t < 15; t++)
//	{
//		strlcat(d1,s1,t);
//		ft_strlcat(d2, s1, t);
//		for (int i = 0; i < 15; i++)
//			printf("%d,",d1[i]);
//		puts("");
//		for (int i = 0; i < 15; i++)	
//			printf("%d,",d2[i]);
//		puts("");
//		printf("%lu\n",strlcat(d1,s1,t));
//		printf("%lu\n",ft_strlcat(d2,s1,t));
//	}
//}

// void	 const_test()
// {
// 	char		str[] = "Hello World";
// 	const char	*ptr;
// 	char *const	ppp = str;
// 	const char * const fff;

// 	ptr = str;
// 	*ppp = 'a';
// 	ppp++;
// 	printf("%c\n", *ptr);
// 	ptr++;
// 	printf("%c\n", *ptr);
// }

void	check_memcmp(void)
{
	char	s1[] = {'a','b','c',200};
	char	s2[] = {'a','b','c',0};
	printf("%d\n", memcmp(s1, s2, 4));
	printf("%d\n", ft_memcmp(s1, s2, 4));
}

void	check_memcpy(void)
{
	char	d1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char	d2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char	s1[] = {'1', '2', '3', 231};
	for (int i = 0; i < 7; i++)
	{
		memcpy(d1, s1, i);
		ft_memcpy(d2, s1, i);
		for (int t = 0; t < 7; t++)
			printf("%d,",d1[t]);
		puts("");
		for (int t = 0; t < 7; t++)
			printf("%d,",d2[t]);
		puts("\n+++++++++++++++");
	}
}

void	check_memmove(void)
{
	for (int i = 0; i < 5; i++)
	{
		char	d1[] = {0,0,1,1,1,1,1};
		//char	r1[] = {0,0,0,0,1,1,1};
		//char	r2[] = {1,1,1,1,1,1,1};
		char	d2[] = {0,0,1,1,1,1,1};
		char	s1[] = {'1', '2', '3', 231};
		memmove(d1, d1+2, i);
		ft_memmove(d2, d2+2, i);
		for (int t = 0; t < 7; t++)
			printf("%d,",d1[t]);
		puts("");
		for (int t = 0; t < 7; t++)
			printf("%d,",d2[t]);
		puts("\n+++++++++++++++");
	}
}

void	check_bzero(void)
{
	for (int t = 0; t < 7; t++)
	{
		char	s1[] = {2,2,2,2,2,2};
		char	s2[] = {2,2,2,2,2,2};
		bzero(s1,t);
		ft_bzero(s2,t);
		for (int i = 0; i < 6; i++)
			printf("%d,",s1[i]);
		puts("");
		for (int i = 0; i < 6; i++)
			printf("%d,",s2[i]);
		puts("\n++++++++++++");
	}
}

void	check_calloc(void)
{
	char	*a = calloc(6,sizeof(char));
	char	*b = ft_calloc(6,sizeof(char));

	for	(int i = 0; i < 6; i++)
		printf("%d,",a[i]);
	puts("");
	for	(int i = 0; i < 6; i++)
		printf("%d,",b[i]);
	puts("");
	free(a);
	free(b);
}

void	check_strdup(void)
{
	const char	s1[] = {1,1,1,1,1,1,1};
	char	*test1 = strdup(s1);
	char	*test2 = ft_strdup(s1);
	
	for(int i = 0; i < 7; i++)
		printf ("%d,",test1[i]);
	puts("");
	for(int i = 0; i < 7; i++)
		printf ("%d,",test2[i]);
	puts("");
	free (test1);
	free (test2);
}

void	check_ft_substr(void)
{
	//char const	s[] = {1,1,1,1,2,2,3,7};
	//char	*s = "libft-test-tokyo";
	//char	*a = ft_substr(s, 3, 4);
	char	*a = ft_substr("tripouille", 1, 1);
	for (int i = 0; i < 2; i++)
		printf("%c,",a[i]);
	puts("");
	free (a);
}

void	check_ft_strjoin(void)
{
	//char	s1[] = "imso";
	//char	s2[] = "sleepy";
	char	s1[] = {1,1,1,1,1,0};
	char	s2[] = {2,2,2,2,2,0};
	char	*a;

	a = ft_strjoin(s1, s2);
	for (int i = 0; i < 10; i++)
		printf("%d,",a[i]);
	puts("");
	free (a);
}

void	check_ft_split(void)
{
	char	**letter = ft_split("hello,world,42,tokyo", ',');
	for (int i = 0; i < 4; i++)
		printf("%s\n",letter[i]);
}

void	check_ft_strtrim(void)
{
	//char	s1[] = "abcd123efg222333321hi";
	//char	set[] = "123";
	char	*result = ft_strtrim("hello world", "world");
	
	for (int i = 0; i < 6; i++)
		printf("%c,",result[i]);
	puts("");
	free(result);
}

void	check_ft_atoi(void)
{
	int	r1 = ft_atoi("9223372036854775808");
	int	r2 = atoi("9223372036854775808");
	printf("%d\n",r1);
	printf("%d\n",r2);
}

void	check_ft_itoa(void)
{
	//char	*result = ft_itoa(-2147483648);
	char	*result = ft_itoa(-123);

	for (int i = 0; i < 5; i++)
		printf("%d,",result[i]);
	puts("");
	free(result);
}

//char	teststrmapi(unsigned int num, char chr)
//{
//	if (!num)
//		return ('a');
//	return (chr);
//}

char addOne(unsigned int i, char c) {return (i + c);}

void	check_ft_strmapi()
{
	const char	s[] = "";
	char	*result = ft_strmapi(s,addOne);

	//for (int i = 0; i < 4; i++)
	printf("%s,",result);
	puts("");
}

void	teststriteri(unsigned int num, char* str)
{
	if (str == NULL)
		return ;

	for (unsigned int i = 0; i < num; i++)
	{
		char lastChar = str[0];
        for (unsigned int j = 1; str[j] != '\0'; j++)
		{
			char temp = str[j];
			str[j] = lastChar;
			lastChar = temp;
		}
        str[0] = lastChar;
	}
}

void	check_ft_striteri(void)
{
	char	s[] = "abcdefg";

	ft_striteri(s,teststriteri);
	for (unsigned int i = 0; i < 7; i++)
		printf("%c,",s[i]);
	puts("");
}

void	check_putnbr_fd(void)
{
	int	n = 12345;

	ft_putnbr_fd(n, 1);
}

int	main(void)
{
	check_ft_strtrim();
	return 0;
}