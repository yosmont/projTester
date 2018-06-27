/*
** EPITECH PROJECT, 2018
** SYN_projTester_2018
** File description:
** get option of this programme
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "project.h"

info_t getoptprog(int ac, char **av, char **env)
{
	info_t info = {NULL, NULL, env, 1};
	DIR *fd_test = NULL;

	if (ac < 2)
		exit_comment(2, "Error: bad number of option\n", 84);
	info.trd = (ac > 1) ? strdup(av[1]) : NULL;
	info.bft = (ac > 2) ? get_binpath(av[2]) : NULL;
	info.fd = (ac > 3) ? open(av[3], O_RDWR | O_TRUNC | O_CREAT, 0777) : 1;
	if (info.trd) {
		fd_test = opendir(info.trd);
		if (fd_test == NULL) {
			free(info.trd);
			info.trd = NULL;
		} else
			closedir(fd_test);
	}
	return (info);
}
