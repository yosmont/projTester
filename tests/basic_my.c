/*
** EPITECH PROJECT, 2018
** SYN_palindrome_2017
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "project.h"

void exit_comment(int fd, char *str, int rtn)
{
	write(fd, str, strlen(str));
	exit(rtn);
}

Test(basic_my, test_parse_and_getbin_function)
{
	cr_expect(calc_nb_letter("hello world", 'o') == 2);
	cr_expect(calc_nb_letter("test/opt1/client/master", '/') == 3);
	cr_expect_str_eq(found_filename("lol/is/shit"), "shit");
}

Test(basic_my, test_getbin)
{
	cr_expect_str_eq(get_binpath("ls"), "/usr/bin/ls");
	cr_expect_str_eq(get_binpath("echo"), "/usr/bin/echo");
	cr_expect_str_eq(get_binpath("projTester"), "projTester");
}

Test(basic_my, test_parse_getbin_compil)
{
	cr_expect(calc_nb_letter(get_binpath("echo"), '/') == 3);
	cr_expect_str_eq(found_filename(get_binpath("ls")), "ls");
}

Test(basic_my, my_strcat_strndup_test)
{
	cr_expect_str_eq(my_strcat(strdup("Hello "), "World!"), "Hello World!");
	cr_expect_str_eq(my_strcat(strdup("BA"), "SIC"), "BASIC");
	cr_expect_str_eq(my_strndup("hello world", 5), "hello");
	cr_expect_str_eq(my_strndup("BASIC", 2), "BA");
}
