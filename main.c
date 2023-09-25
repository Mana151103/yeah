/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:21:36 by mosada            #+#    #+#             */
/*   Updated: 2023/09/25 22:21:38 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

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

void	check_strlcat(void)
{
	char	d1[15] = {'a', 'a', 'a', 'a', 'a', '\0', 1, 1, 1, 1, 1, 1, 1, 1, 1};
	char	d2[15] = {'a', 'a', 'a', 'a', 'a', '\0', 1, 1, 1, 1, 1, 1, 1, 1, 1};
	const char	s1[] = "123";
	for (int t = 0; t < 15; t++)
	{
		strlcat(d1,s1,t);
		ft_strlcat(d2, s1, t);
		for (int i = 0; i < 15; i++)
			printf("%d,",d1[i]);
		puts("");
		for (int i = 0; i < 15; i++)	
			printf("%d,",d2[i]);
		puts("");
		printf("%lu\n",strlcat(d1,s1,t));
		printf("%lu\n",ft_strlcat(d2,s1,t));
	}
}

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
}