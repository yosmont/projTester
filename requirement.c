/*
** EPITECH PROJECT, 2018
** SYN_projTester_2018
** File description:
** requirement
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_ps_synthesis(void)
{
	char *env[1] = {NULL};
	char *av[2] = {"ps", NULL};
	pid_t id = fork();

	if (id == -1)
		exit(84);
	else if (id == 0) {
		execve("/bin/ps", av, env);
		exit(84);
	} else {
		wait(NULL);
		exit(84);
	}
}
