/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** testlist function
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

static testlist_t *testlist_bubblesort(testlist_t *list)
{
	void *tmp = NULL;
	int check = 0;
	testlist_t *begin = list;

	while (list && list->next) {
		if (strcmp(list->filepath, list->next->filepath) > 0) {
			tmp = list->filepath;
			list->filepath = list->next->filepath;
			list->next->filepath = tmp;
			check = 1;
		}
		list = list->next;
	}
	if (check == 1)
		begin = testlist_bubblesort(begin);
	return (begin);
}

static testlist_t *init_test_list(void)
{
	testlist_t *new = malloc(sizeof(testlist_t));

	new->filepath = NULL;
	new->av = NULL;
	new->input = 0;
	new->res = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static testlist_t *create_testlist_recu(char *filepath, testlist_t *list)
{
	DIR *dir = opendir(filepath);
	struct dirent *file = readdir(dir);
	char *tmp = NULL;

	while (file) {
		tmp = my_strcat(my_strcat(strdup(filepath), "/"), file->d_name);
		if (file->d_name[0] != '.') {
			list->filepath = strdup(tmp);
			list->next = init_test_list();
			list->next->prev = list;
			list = list->next;
		}
		if (file->d_name[0] != '.' && file->d_type == DT_DIR)
			list = create_testlist_recu(tmp, list);
		free(tmp);
		file = readdir(dir);
	}
	closedir(dir);
	return (list);
}

testlist_t *create_testlist(char *filepath)
{
	testlist_t *list = init_test_list();
	testlist_t *begin = list;

	if (filepath[strlen(filepath) - 1] == '/')
		filepath[strlen(filepath) - 1] = '\0';
	list = create_testlist_recu(filepath, list);
	if (list->prev)
		list->prev->next = NULL;
	else
		begin = NULL;
	free(list);
	list = NULL;
	return (testlist_bubblesort(begin));
}

void free_testlist(testlist_t *list)
{
	void *tmp = NULL;

	while (list) {
		tmp = list->next;
		if (list->filepath)
			free(list->filepath);
		if (list->av)
			free_tab(list->av);
		if (list->input != 0 && list->input != -1)
			close(list->input);
		if (list->res)
			free(list->res);
		free(list);
		list = tmp;
	}
}
