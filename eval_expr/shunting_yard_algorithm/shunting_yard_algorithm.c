/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** algorithm to generate the reverse polish notation
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include_eval_expr/shunting_yard_algorithm.h"

static void empty_stack_remain(eval_expr_t *eval_expr)
{
	char *get_stack_data = eval_expr->sy_algo.get_stack_data;

	while (eval_expr->stack != NULL) {
		get_stack_data = pop_stack(&eval_expr->stack);
		eval_expr->queue =
		push_queue(eval_expr->queue, (void *)get_stack_data);
	}
}

extern bool shunting_yard_algo(eval_expr_t *eval_expr)
{
	if (lexer_bistro(&eval_expr->lexer_b) == ERROR)
		return (ERROR);
	while (eval_expr->lexer_b.lexem_type != TOKEN_END) {
		verified_token_operator(eval_expr);
		verified_other_token(eval_expr);
		if (lexer_bistro(&eval_expr->lexer_b) == ERROR)
			return (ERROR);
	}
	empty_stack_remain(eval_expr);
	return (SUCCESS);
}

extern eval_expr_t initialize_var(eval_expr_t eval_expr, char *buf)
{
	eval_expr.lexer_b
	= initialize_var_lexer(eval_expr.lexer_b, buf);
	eval_expr.stack = NULL;
	eval_expr.queue = NULL;
	eval_expr.sy_algo.get_stack_data = NULL;
	eval_expr.sy_algo.get_queue_data = NULL;
	return (eval_expr);
}
