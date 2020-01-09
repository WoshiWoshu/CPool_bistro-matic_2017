/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/do_op.h"
#include "include_eval_expr/shunting_yard_algorithm.h"

static void proceed_operation(eval_expr_t *eval_expr)
{
	int *pos = &(eval_expr->lexer_b.pos);
	char **npi_string = eval_expr->lexer_b.npi_string;
	char *get_stack_data_1 = NULL;
	char *get_stack_data_2 = NULL;
	long long result = 0;

	get_stack_data_1 = pop_stack(&eval_expr->stack);
	get_stack_data_2 = pop_stack(&eval_expr->stack);
	result = do_op(get_stack_data_2,
		get_stack_data_1, npi_string[*pos][0]);
	eval_expr->stack =
		push_stack(eval_expr->stack, (void *)(my_itoal(result)));
}

static char **cpy_npi_notation_from_queue_to_string(eval_expr_t *eval_expr)
{
	char **npi_string = eval_expr->lexer_b.npi_string;
	int *pos = &(eval_expr->lexer_b.pos);

	*pos = 0;
	for (llist_t *tmp = eval_expr->queue; tmp != NULL; tmp = tmp->next) {
		npi_string[*pos] = malloc(sizeof(my_strlen(tmp->data)));
		my_strcat(npi_string[*pos], tmp->data);
		npi_string[*pos][my_strlen(tmp->data)] = '\0';
		*pos = *pos + 1;
	}
	npi_string[*pos] = NULL;
	return (npi_string);
}

extern void eval_expr_func(eval_expr_t *eval_expr)
{
	char **npi_string = eval_expr->lexer_b.npi_string;
	int *pos = &(eval_expr->lexer_b.pos);

	npi_string = cpy_npi_notation_from_queue_to_string(eval_expr);
	for (*pos = 0; npi_string[*pos] != NULL; *pos += 1) {
		if (npi_string[*pos][0] >= '0' && npi_string[*pos][0] <= '9')
			eval_expr->stack =
			push_stack(eval_expr->stack, npi_string[*pos]);
		if (npi_string[*pos][0] == '+' || npi_string[*pos][0] == '-'
		|| npi_string[*pos][0] == '*' || npi_string[*pos][0] == '%'
		|| npi_string[*pos][0] == '/')
			proceed_operation(eval_expr);
	}
}

static void handle_first_minus_sign(eval_expr_t *eval_expr)
{
	char *new_buf = malloc(sizeof(char) *
	my_strlen(eval_expr->bistro.buf) * 2);

	for (int i = 0; eval_expr->bistro.buf[i] != '\0'; i++) {
		if (eval_expr->bistro.buf[i] == '-') {
			new_buf[0] = '0';
			my_strcat(new_buf, eval_expr->bistro.buf);
			break;
		} else {
			my_strcpy(new_buf, eval_expr->bistro.buf);
			break;
		}
		new_buf[i] = eval_expr->bistro.buf[i];
	}
	eval_expr->bistro.buf[0] = 0;
	my_strcpy(eval_expr->bistro.buf, new_buf);
	free(new_buf);
}

int main(int ac, char **av)
{
	eval_expr_t eval_expr;

	if (ac != 4) {
		write(2, ERROR_MSG, 5);
		return (84);
	}
	bistro_preliminary(&eval_expr, av);
	eval_expr = initialize_var(eval_expr, eval_expr.bistro.buf);
	handle_first_minus_sign(&eval_expr);
	if (shunting_yard_algo(&eval_expr) == ERROR) {
		write(2, SYNTAX_ERROR_MSG, 12);
		return (84);
	}
	eval_expr_func(&eval_expr);
	if (count_stack_queue(eval_expr.stack) > 1) {
		write(2, SYNTAX_ERROR_MSG, 12);
		return (84);
	}
	display_stack_queue(eval_expr.stack);
	return (0);
}
