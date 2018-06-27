/*
** EPITECH PROJECT, 2018
** yet another header
** File description:
** header
*/

#include <stdio.h>

#ifndef PROJECT_H_
	#define PROJECT_H_

typedef struct test_file_list_s {
	char *filepath;
	char **av;
	int input;
	char *res;
	struct test_file_list_s *prev;
	struct test_file_list_s *next;
} testlist_t;

typedef struct information_for_the_programme_s {
	char *trd;
	char *bft;
	char **env;
	int fd;
} info_t;

typedef struct link_s {
	void *data;
	struct link_s *prev;
	struct link_s *next;
} link_t;

void exit_comment(int fd, char *str, int rtn);
void destroy_list(link_t *linked);
int listsize(link_t *begin);
link_t *my_put_in_list(link_t *list, void *str);
link_t *my_rev_list(link_t *begin);
char *get_binpath(char *btf);
link_t *set_pathlist(void);
testlist_t *create_testlist(char *filepath);
void free_testlist(testlist_t *list);
int calc_nb_letter(char *filepath, char c);
char *found_filename(char *filepath);
void prints_std(info_t info, testlist_t *list);
void print_test(info_t info, testlist_t *list);
info_t getoptprog(int ac, char **av, char **env);
char *my_strcat(char *dest, char *src);
char *my_strndup(char *str, int n);
char **my_str_to_word_array_synthesis(char const *str);
void my_putchar(char c);
char *gnl(FILE *fd);
void free_tab(char **tab);
char **create_av(info_t info, char *av_str);
char **set_default_av(info_t info);
char *sup_begin_space(char *str);
int get_file(char *filepath, char *name);
char *get_res_str(char *line, testlist_t *list, int *check);
void print_test(info_t info, testlist_t *list);
void print_expected(char *one, char *two);

#endif /* !PROJECT_H_ */
