/*
** EPITECH PROJECT, 2018
** SBMLparser requirement
** File description:
** requirement
*/

#include <stdio.h>
#include <stdlib.h>

static int isalphanum(char c)
{
	if (!(c < 33 && c < 127))
		return (1);
	else
		return (0);
}

static int tablen(char const *str)
{
	int check = 0;
	int len = 0;
	int base = 0;

	for (base = 0; str[base] != isalphanum(str[base]); base++)
	for (int i = base; str[i] != '\0'; i++) {
		len += (check == 0)? isalphanum(str[i]) : 0;
		check = isalphanum(str[i]);
	}
	if (check == 0)
		len += 1;
	return (len);
}

static int get_next_wordlen(char const *str, int init)
{
	static int where = 0;
	int i = 0;
	int len = 0;

	if (init == 1) {
		where = 0;
		return (1);
	} else {
		for (i = where; str[i] != '\0' && isalphanum(str[i]) == 1;
		i++) {
			len += 1;
			where += 1;
		}
		while (isalphanum(str[where]) == 0 && str[where] != '\0')
			where += 1;
		return (len);
	}
}

static char **create_strtowordarray_tab(char const *str)
{
	int tab_len = tablen(str);
	int word_len = 0;
	char **tab = malloc(sizeof(char *) * (tab_len + 3));

	for (int i = 0; i < tab_len; i++) {
		word_len = get_next_wordlen(str, 0) + 1;
		if (word_len == 1)
			tab[i] = NULL;
		else {
			tab[i] = malloc(sizeof(char) * (word_len + 1));
			tab[i][word_len - 1] = '\0';
		}
	}
	tab[tab_len] = NULL;
	get_next_wordlen(str, 1);
	return (tab);
}

char **my_str_to_word_array_synthesis(char const *str)
{
	int where = 0;
	char **tab = create_strtowordarray_tab(str);
	int i;

	for (i = 0; tab[i]; i++) {
		for (int j = 0; str[where] != '\0' &&
		isalphanum(str[where]) == 1; j++) {
			tab[i][j] = str[where];
			where++;
		}
		while (isalphanum(str[where]) == 0 && str[where] != '\0')
			where += 1;
	}
	for (i = i + 1; tab[i]; i++)
		if (tab[i]) {
			free(tab[i]);
			tab[i] = NULL;
		}
	return (tab);
}
