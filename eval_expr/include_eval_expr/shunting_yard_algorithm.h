/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** shunting yard algo header
*/

#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include <stdbool.h>
#include <unistd.h>
#include "../../include/lexer_bistro.h"
#include "../../include/llist_stack_queue_simple.h"

typedef struct sy_algo_s
{
	char *get_stack_data;
	char *get_queue_data;
} sy_algo_t;

typedef struct bistro_s
{
	size_t count;
	char *buf;
} bistro_t;

typedef struct eval_expr_s
{
	lexer_b_t lexer_b;
	llist_t *stack;
	llist_t *queue;
	sy_algo_t sy_algo;
	bistro_t bistro;
} eval_expr_t;

static const char SYNTAX_ERROR_MSG[] = "syntax error";
static const char ERROR_MSG[] = "error";

extern void verified_other_token(eval_expr_t *eval_expr);
extern void verified_token_operator(eval_expr_t *eval_expr);
extern eval_expr_t initialize_var(eval_expr_t eval_expr, char *buf);
extern bool shunting_yard_algo(eval_expr_t *eval_expr);
extern void bistro_preliminary(eval_expr_t *eval_expr, char **av);

#endif /* SHUNTING_YARD_H */
