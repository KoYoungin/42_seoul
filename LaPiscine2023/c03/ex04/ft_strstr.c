/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:43:47 by younko            #+#    #+#             */
/*   Updated: 2023/02/23 10:42:17 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
		i++;
	}
	if (i != n)
	{
		if (*s2 != '\0')
			return (0 - (int) *s2);
		else if (*s1 != '\0')
			return ((int) *s1);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*addr;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			addr = str;
			if (ft_strncmp(str, to_find, ft_strlen(to_find)) == 0)
				return (addr);
		}
		str++;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define PASS(res) res == 0 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) : printf( RED " (x)"  RESET );
#define RET(res, ret) res == 0 ? printf( GREEN "\"%s\"\n" RESET, ret) : printf( RED "\"%s\"\n" RESET, ret);
int main()
{
	char str[] = "Hello les loulous";
	char str2[] = "";
    char to_find[] = "lou";
    char to_find2[] = "";
    char to_find3[] = "jonathan";
    char to_find4[] = "Hello les loulous";
    char to_find5[] = "Hello les louloust";
    char to_find6[] = "H";

	char *r = ft_strstr(str, to_find);
	char *libr = strstr(str, to_find);

	char *r2 = ft_strstr(str, to_find2);
	char *libr2 = strstr(str, to_find2);

	char *r3 = ft_strstr(str, to_find3);
	char *libr3 = strstr(str, to_find3);

	char *r4 = ft_strstr(str2, to_find);
	char *libr4 = strstr(str2, to_find);

	char *r5 = ft_strstr(str, to_find4);
	char *libr5 = strstr(str, to_find4);

	char *r6 = ft_strstr(str, to_find5);
	char *libr6 = strstr(str, to_find5);

	char *r7 = ft_strstr(str, to_find6);
	char *libr7 = strstr(str, to_find6);




	printf(YELLOW "\nTEST1 : There is an occurence" RESET);
	PASS(r != 0 && strcmp(r, libr))
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n\n", to_find);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r != 0 && strcmp(r, libr), r)
	printf("lib function: \"%s\"\n\n", libr);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST2 : to_find parameter is empty" RESET);
	PASS(r2 != 0 && strcmp(r2, libr2))
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n", to_find2);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r2 != 0 && strcmp(r2, libr2), r2)
	printf("lib function: \"%s\"\n\n", libr2);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST3 : There is no occurence");
	PASS((r3 == 0 && libr3 == 0) == 0)
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n", to_find3);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
	RET((r3 == 0 && libr3 == 0) == 0, r3)
	printf("lib function: \"%s\"\n\n", libr3);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST4 : str is empty");
	PASS((r4 == 0 && libr4 == 0 ) == 0)
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str2);
	printf("to_find: \"%s\"\n", to_find);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET((r4 == 0 && libr4 == 0) == 0, r4)
	printf("lib function: \"%s\"\n\n", libr4);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST5 : str and to_find is same" RESET);
	PASS(r5 != 0 && strcmp(r5, libr5))
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n", to_find4);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r5 != 0 && strcmp(r5, libr5), r5)
	printf("lib function: \"%s\"\n\n", libr5);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST6 : to_find has one more different char" RESET);
	PASS((r6 == 0 && libr6 == 0) == 0)
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n", to_find5);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET((r6 == 0 && libr6 == 0) == 0, r6)
	printf("lib function: \"%s\"\n\n", libr6);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST7 : to_find is H" RESET);
	PASS(r7 != 0 && strcmp(r7, libr7))
	printf("\n" );
	printf("-------------------------------\n");
	printf("str: \"%s\"\n", str);
	printf("to_find: \"%s\"\n", to_find6);
	printf("\n" );
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r7 != 0 && strcmp(r7, libr7), r7)
	printf("lib function: \"%s\"\n\n", libr7);
	printf("-------------------------------\n\n");

}
