/*
** EPITECH PROJECT, 2018
** yet another main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "project.h"

void exit_comment(int fd, char *str, int rtn)
{
	write(fd, str, strlen(str));
	exit(rtn);
}

static void free_info(info_t info)
{
	if (info.trd)
		free(info.trd);
	if (info.bft)
		free(info.bft);
	if (info.fd != 1 && info.fd != -1)
		close(info.fd);
}

int main(int ac, char **av, char **env)
{
	info_t info = getoptprog(ac, av, env);
	testlist_t *list = (info.trd) ? create_testlist(info.trd) : NULL;
	void *begin = list;
	int rtn = 0;

	if (!info.trd || (ac > 2 && !info.bft) || info.fd == -1) {
		write(2, "Error: bad arg\n", 15);
		rtn = 84;
	} else if (!info.bft)
		prints_std(info, begin);
	else
		print_test(info, begin);
	free_testlist(begin);
	free_info(info);
	return (rtn);
}
