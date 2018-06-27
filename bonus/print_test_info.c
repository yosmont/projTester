/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** print test info
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "project.h"

static void print_line(char c, int len)
{
	for (int i = 0; i < len; i++)
		write(1, &c, 1);
	write(1, "\n", 1);
}

static void print_expected_tab(void)
{
	static int i = 0;
	int nb = i;

	i = (i == 0) ? 1 : 0;
	for (int j = 0; j < 8; j++) {
		if ((nb % 2) == 0)
			write(1, "\\", 1);
		else
			write(1, "/", 1);
		nb++;
	}
	write(1, "|", 1);
}

void print_expected(char *one, char *two)
{
	int len = (strlen(one) > strlen(two)) ? strlen(one) : strlen(two);

	len = (len > 71) ? 71 : len;
	print_expected_tab();
	write(1, "Expected:\n", 10);
	print_expected_tab();
	print_line('=', len);
	print_expected_tab();
	write(1, one, strlen(one));
	print_expected_tab();
	print_line('=', len);
	print_expected_tab();
	write(1, "got:\n", 5);
	print_expected_tab();
	print_line('=', len);
	print_expected_tab();
	write(1, two, strlen(two));
	print_expected_tab();
	print_line('=', len);
}
