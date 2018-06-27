/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** search btf
*/

#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "project.h"

static char *found_exec(char *btf, struct dirent *f, link_t *path)
{
	char *binpath = strdup("\0");
	char *tmp = NULL;

	if (strcmp(f->d_name, btf) == 0) {
		tmp = my_strcat(my_strcat(strdup(path->data), "/"), f->d_name);
		binpath = my_strcat(binpath, tmp);
		free(tmp);
		return (binpath);
	}
	free(binpath);
	return (NULL);
}

static DIR *good_dir(link_t *path, DIR *dir)
{
	dir = opendir(path->data);
	while (dir == NULL && path->next != NULL) {
		path = path->next;
		dir = opendir(path->data);
	}
	return (dir);
}

static char *search_exec(char *btf)
{
	link_t *path = set_pathlist();
	link_t *path_begin = path;
	char *binpath = NULL;
	DIR *dir = NULL;
	struct dirent *file;

	while (path != NULL && !binpath) {
		dir = good_dir(path, dir);
		file = readdir(dir);
		while (file && !binpath) {
			binpath = found_exec(btf, file, path);
			file = readdir(dir);
		}
		closedir(dir);
		dir = NULL;
		path = path->next;
	}
	destroy_list(path_begin);
	return (binpath);
}

char *get_binpath(char *btf)
{
	DIR *dir = opendir(".");
	struct dirent *file = readdir(dir);
	char *binpath = (btf[0] == '/' || btf[0] == '.') ? strdup(btf) : NULL;

	while (file && !binpath) {
		if (strcmp(file->d_name, btf) == 0)
			binpath = strdup(btf);
		file = readdir(dir);
	}
	closedir(dir);
	if (!binpath && getenv("PATH") != NULL)
		binpath = search_exec(btf);
	return (binpath);
}
