/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** print function
*/

#include <stdio.h>
#include <string.h>
#include "project.h"

int calc_nb_letter(char *filepath, char c)
{
	int nb = 0;

	for (int i = 0; filepath[i] != '\0'; i++)
		if (filepath[i] == c)
			nb++;
	return (nb);
}

char *found_filename(char *filepath)
{
	int len = 0;

	for (len = strlen(filepath); len > -1 && filepath[len] != '/'; len--);
	len++;
	return (&filepath[len]);
}

void prints_std(info_t info, testlist_t *list)
{
	int indent = 0;
	void *begin = list;

	printf("%s\n", found_filename(info.trd));
	while (list) {
		indent = calc_nb_letter(list->filepath, '/') -
		calc_nb_letter(info.trd, '/');
		for (int i = 0; i < indent; i++)
			printf("-----");
		printf("%s\n", found_filename(list->filepath));
		list = list->next;
	}
	list = begin;
}
