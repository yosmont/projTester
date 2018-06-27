/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** test function
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

char **create_av(info_t info, char *av_str)
{
	char **av = my_str_to_word_array_synthesis(sup_begin_space(av_str));
	int i = 0;

	for (i = 0; av[i] != NULL; i++);
	av[i + 1] = NULL;
	for (i = i; i > 0; i--)
		av[i] = av[i - 1];
	av[0] = strdup(found_filename(info.bft));
	return (av);
}

char **set_default_av(info_t info)
{
	char **new = malloc(sizeof(char *) * 3);

	new[0] = strdup(found_filename(info.bft));
	new[1] = NULL;
	return (new);
}

int get_file(char *filepath, char *name)
{
	int len = strlen(filepath) - strlen(found_filename(filepath));
	char *newpath = my_strcat(my_strndup(filepath, len), name);
	int fd = open(newpath, O_RDONLY);

	if (fd == -1) {
		fd = 0;
		write(2, "Error: file missing\n", 20);
	}
	free(newpath);
	return (fd);
}

char *get_res_str(char *line, testlist_t *list, int *check)
{
	char var_name[3][7] = {"ARGS:", "INPUT:", "RES:"};

	if (*check == 0 &&
	strncmp(line, var_name[2], strlen(var_name[2])) == 0) {
		*check = 1;
		list->res = strdup(&line[strlen(var_name[2])]);
	} else if (strncmp(line, var_name[0], strlen(var_name[0])) == 0 ||
	strncmp(line, var_name[1], strlen(var_name[1])) == 0) {
		*check = 0;
	} else {
		list->res = my_strcat(my_strcat(list->res, "\n"), line);
	}
	return (list->res);
}

char *sup_begin_space(char *str)
{
	while ((str[0] < 33 && str[0] < 127))
		str++;
	return (str);
}
