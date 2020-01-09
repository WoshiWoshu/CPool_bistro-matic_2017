/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** functions that verified the different token and then make the npi notation
*/

#include <stddef.h>
#include "../include_eval_expr/shunting_yard_algorithm.h"

static void token_operator_process(eval_expr_t *eval_expr)
{
	char *get_stack_data = eval_expr->sy_algo.get_stack_data;
	char compare = eval_expr->lexer_b.lexem[1];
	llist_t *tmp = eval_expr->stack;

	if (tmp != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (((char *)tmp->data)[1] > compare) {
			get_stack_data = pop_stack(&eval_expr->stack);
			eval_expr->queue =
			push_queue(eval_expr->queue, (void *)get_stack_data);
			token_operator_process(eval_expr);
		}
	}
}

extern void verified_token_operator(eval_expr_t *eval_expr)
{
	char token_type = eval_expr->lexer_b.lexem_type;

	if (token_type == TOKEN_MOD || token_type == TOKEN_MIN
	|| token_type == TOKEN_PLUS || token_type == TOKEN_DIV
	|| token_type == TOKEN_MULT) {
		token_operator_process(eval_expr);
		eval_expr->stack =
		push_stack(eval_expr->stack,
		(void *)eval_expr->lexer_b.lexem);
	}
	return;
}

static void token_right_parenthesis_handle(eval_expr_t *eval_expr)
{
	llist_t *tmp = eval_expr->stack;
	char *get_stack_data = eval_expr->sy_algo.get_stack_data;

	if (tmp != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (((char *)tmp->data)[0] != '(') {
			get_stack_data = pop_stack(&eval_expr->stack);
			eval_expr->queue =
			push_queue(eval_expr->queue, (void *)get_stack_data);
			token_right_parenthesis_handle(eval_expr);
		}
		if (((char *)tmp->data)[0] == '(')
			pop_stack(&eval_expr->stack);
	}
	return;
}

/*5: number, 6: parenthesis left, 7: parenthesis right*/
extern void verified_other_token(eval_expr_t *eval_expr)
{
	char token_type = eval_expr->lexer_b.lexem_type;
	char *token_container = eval_expr->lexer_b.lexem;

	switch (token_type) {
	case 5:
		eval_expr->queue =
		push_queue(eval_expr->queue, (void *)token_container);
		break;
	case 6:
		eval_expr->stack =
		push_stack(eval_expr->stack, (void *)token_container);
		break;
	case 7:
		token_right_parenthesis_handle(eval_expr);
		break;
	default:
		break;
	}
}
