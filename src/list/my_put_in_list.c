/*
** EPITECH PROJECT, 2018
** list
** File description:
** link_t lib function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

link_t *my_put_in_list(link_t *list, void *str)
{
	link_t *element = malloc(sizeof(link_t));

	element->data = strdup(str);
	element->next = list;
	if (list != NULL)
		list->prev = element;
	list = element;
	free(str);
	return (list);
}
