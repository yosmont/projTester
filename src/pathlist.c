/*
** EPITECH PROJECT, 2018
** SYN_projTester_2018
** File description:
** pathlist function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

static int nb_path(char *all_path)
{
	int nb = 1;

	for (int i = 0; all_path[i] != '\0'; i++)
		if (all_path[i] == ':')
			nb++;
	return (nb);
}

static int path_len(char *all_path)
{
	int len = 0;

	for (len = 0; all_path[len] != ':' && all_path[len] != '\0'; len++);
	len = len;
	return (len);
}

link_t *set_pathlist(void)
{
	char *all_path = getenv("PATH") + 5;
	link_t *linked = NULL;
	int len = 0;
	int nb = nb_path(all_path);
	char *tmp = NULL;

	for (int i = 0; i < nb; i++) {
		len = path_len(all_path);
		tmp = strndup(all_path, len);
		linked = my_put_in_list(linked, strdup(tmp));
		free(tmp);
		all_path = all_path + (len + 1);
	}
	linked->prev = NULL;
	linked = my_rev_list(linked);
	return (linked);
}
