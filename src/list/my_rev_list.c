/*
** EPITECH PROJECT, 2018
** list
** File description:
** link_t lib function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

link_t *my_rev_list(link_t *begin)
{
	link_t *tmp;
	link_t *res;
	void *tmp_two;

	tmp = begin;
	res = NULL;
	while (tmp != NULL) {
		res = my_put_in_list(res, tmp->data);
		tmp_two = tmp;
		tmp = tmp->next;
		free(tmp_two);
	}
	begin = res;
	return (begin);
}
