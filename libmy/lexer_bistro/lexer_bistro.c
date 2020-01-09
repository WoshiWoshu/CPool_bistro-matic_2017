/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** functions that parse the line and put it into token for the eval_expr
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/my.h"
#include "../../include/lexer_bistro.h"

const int TOKEN_NB = 5;
const int TOKEN_PAR_L = 6;
const int TOKEN_PAR_R = 7;
const int TOKEN_MOD = 8;
const int TOKEN_END = 9;

extern lexer_b_t initialize_var_lexer(lexer_b_t lexer_b, char *av_1)
{
	lexer_b.pos = 0;
	lexer_b.lexem_type = 0;
	lexer_b.lexem = malloc(sizeof(my_strlen(av_1)) * 10);
	lexer_b.npi_string = malloc(10000);
	lexer_b.line = av_1;
	return (lexer_b);
}

extern bool lexer_bistro(lexer_b_t *lexer_b)
{
	lexer_b->lexem = malloc(sizeof(my_strlen(lexer_b->line)));
	while (lexer_b->pos < my_strlen(lexer_b->line)
	&& lexer_b->line[lexer_b->pos] == ' ')
		lexer_b->pos +=1;
	if (lexer_b->pos >= my_strlen(lexer_b->line))
		lexer_b->lexem_type = TOKEN_END;
	else
		if (check_token_number(lexer_b)
		&& check_token_non_priority(lexer_b)
		&& check_token_parenthesis(lexer_b)
		&& check_token_priority(lexer_b) == ERROR)
			return (ERROR);
	return (SUCCESS);
}
