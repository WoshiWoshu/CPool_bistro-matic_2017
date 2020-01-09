/*
** EPITECH PROJECT, 2018
** bistro_matic
** File description:
** functions that prepare the bistro
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "include_eval_expr/shunting_yard_algorithm.h"

static void init_var_bistro(bistro_t *bistro)
{
	bistro->buf = malloc(sizeof(char) * bistro->count + 1);
	if (bistro->buf == NULL) {
		write(2, ERROR_MSG, 5);
		exit(84);
	}
}

static void check_error_av(bistro_t *bistro, char **av)
{
	for (int i = 0; av[1][i] != '\0'; ++i)
		if (av[1][i] < '0' || av[1][i] > '9') {
			write(2, ERROR_MSG, 5);
			exit(84);
		}
	for (int i = 0; av[2][i] != '\0'; ++i)
		if (av[2][i] != '(' && av[2][i] != ')'
		&& av[2][i] != '+' && av[2][i] != '-'
		&& av[2][i] != '*' && av[2][i] != '/'
		&& av[2][i] != '%') {
			write(2, ERROR_MSG, 5);
			exit(84);
		}
	for (int i = 0; av[3][i] != '\0'; ++i)
		if (av[3][i] < '0' || av[3][i] > '9') {
			write(2, ERROR_MSG, 5);
			exit(84);
		}
	bistro->count = my_getnbr(av[3]);
}

extern void bistro_preliminary(eval_expr_t *eval_expr, char **av)
{
	signed short i = 0;

	check_error_av(&(eval_expr->bistro), av);
	init_var_bistro(&(eval_expr->bistro));
	read(0, eval_expr->bistro.buf, eval_expr->bistro.count);
	while (eval_expr->bistro.buf[i] != '\0') {
		if (eval_expr->bistro.buf[i] == '\n') {
			eval_expr->bistro.buf[i] = '\0';
			break;
		}
		i++;
	}
	return;
}
