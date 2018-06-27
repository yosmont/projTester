/*
** EPITECH PROJECT, 2018
** list
** File description:
** link_t lib function
*/

#include <stdlib.h>
#include "project.h"

int listsize(link_t *begin)
{
	int size = 0;
	link_t *tmp;

	tmp = begin;
	while (tmp != NULL) {
		size++;
		tmp = tmp->next;
	}
	return (size);
}
