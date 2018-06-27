/*
** EPITECH PROJECT, 2018
** SYN_projTester_2017
** File description:
** free function
*/

#include <stdlib.h>
#include "project.h"

void free_tab(char **tab)
{
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
