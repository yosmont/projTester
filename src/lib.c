/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** lib
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "project.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *my_strcat(char *dest, char *src)
{
	int len = strlen(dest);
	int tmp = 0;
	char *res = malloc(sizeof(char) * (len + strlen(src) + 1));

	for (int i = 0; i < len; i++)
		res[i] = dest[i];
	free(dest);
	while (src[tmp] != '\0') {
		res[len] = src[tmp];
		len++;
		tmp++;
	}
	res[len] = '\0';
	dest = strdup(res);
	free(res);
	return (dest);
}

char *my_strndup(char *str, int n)
{
	char *new = malloc(sizeof(char) * (n + 1));

	for (int i = 0; i < n; i++)
		new[i] = str[i];
	new[n] = '\0';
	return (new);
}

char *straddc(char *str, char c)
{
	int len = strlen(str);
	char *res = malloc(sizeof(char) * (len + 2));

	for (int i = 0; i < len; i++)
		res[i] = str[i];
	free(str);
	res[len] = c;
	res[len + 1] = '\0';
	str = strdup(res);
	free(res);
	return (str);
}
