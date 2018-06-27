/*
** EPITECH PROJECT, 2018
** list
** File description:
** link_t lib function
*/

#include <stdlib.h>
#include "project.h"

void destroy_list(link_t *linked)
{
	void *tmp = NULL;

	while (linked != NULL) {
		tmp = linked->next;
		if (linked->data)
			free(linked->data);
		free(linked);
		linked = tmp;
	}
}
