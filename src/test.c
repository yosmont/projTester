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

static testlist_t *get_tdf_info(info_t info, testlist_t *list)
{
	FILE *fd = fopen(list->filepath, "r");
	char var_name[3][7] = {"ARGS:", "INPUT:", "RES:"};
	char *line = gnl(fd);
	int check = 0;

	while (line) {
		line[strlen(line) - 1] = (line[strlen(line) - 1] == '\n') ? '\0'
		: line[strlen(line) - 1];
		if (strncmp(line, var_name[0], strlen(var_name[0])) == 0)
			list->av = create_av(info,
			sup_begin_space(&line[strlen(var_name[0])]));
		if (strncmp(line, var_name[1], strlen(var_name[1])) == 0)
			list->input = get_file(list->filepath,
			sup_begin_space(&line[strlen(var_name[1])]));
		list->res = get_res_str(line, list, &check);
		free(line);
		line = gnl(fd);
	}
	list->res = (check == 1)? my_strcat(list->res, "\n") : list->res;
	list->av = (!list->av) ? set_default_av(info) : list->av;
	fclose(fd);
	return (list);
}

static void print_test_name(char *filepath, char *ref, testlist_t *list)
{
	char *begin = filepath;
	int nb = calc_nb_letter(filepath, '/') - 1 - calc_nb_letter(ref, '/');

	filepath += strlen(ref) + 1;
	for (int i = 0; i < nb; i++) {
		my_putchar('[');
		while (filepath[0] != '/') {
			my_putchar(filepath[0]);
			filepath++;
		}
		filepath++;
		write(1, "] ", 2);
	}
	filepath = begin;
	begin = found_filename(filepath);
	begin = my_strcat(my_strndup(begin, (strlen(begin) - 4)),
	(list->av[1] == NULL && list->input == 0) ? ":" : ": ");
	write(1, begin, strlen(begin));
	free(begin);
}

static void print_res(FILE *fd, testlist_t *list)
{
	char *buf;
	char *res = malloc(sizeof(char));

	res[0] = '\0';
	buf = gnl(fd);
	while (buf) {
		res = my_strcat(res, buf);
		free(buf);
		buf = gnl(fd);
	}
	if (list->res) {
		if (strcmp(res, list->res) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	fclose(fd);
	free(buf);
	free(res);
}

static void exec_test(info_t info, testlist_t *test)
{
	pid_t id = fork();
	int test_fd = (test->res) ?
	open(".projTesterTmp", O_CREAT | O_TRUNC | O_RDWR, 0777) : 1;
	char *default_env[1] = {NULL};

	if (id == -1)
		exit(84);
	else if (id == 0) {
		dup2(test_fd, 1);
		dup2(test->input, 0);
		execve(info.bft, test->av, (info.env) ? info.env : default_env);
		exit(84);
	} else {
		wait(NULL);
		if (test->res)
			print_res(fdopen(test_fd, "r"), test);
	}
	if (test->res) {
		close(test_fd);
		remove(".projTesterTmp");
	}
}

void print_test(info_t info, testlist_t *list)
{
	dup2(info.fd, 1);
	while (list) {
		if (strcmp(&list->filepath[strlen(list->filepath) - 4],
		".tdf") == 0) {
			list = get_tdf_info(info, list);
			print_test_name(list->filepath, info.trd, list);
			exec_test(info, list);
		}
		list = list->next;
	}
}
