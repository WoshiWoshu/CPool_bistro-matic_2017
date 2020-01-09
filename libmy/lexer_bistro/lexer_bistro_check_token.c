/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** functions that check the token for the bistro lexer
*/

#include <stdbool.h>
#include "../../include/my.h"
#include "../../include/lexer_bistro.h"

extern bool check_token_priority(lexer_b_t *lexer_b)
{
	char token = lexer_b->line[lexer_b->pos];

	switch (token) {
	case '/':
		lexer_b->lexem_type = TOKEN_DIV;
		my_strcpy(lexer_b->lexem, GRAMMAR[2]);
		lexer_b->pos+=1;
		return (SUCCESS);
	case '%':
		lexer_b->lexem_type = TOKEN_MOD;
		my_strcpy(lexer_b->lexem, GRAMMAR[3]);
		lexer_b->pos+=1;
		return (SUCCESS);
	case '*':
		lexer_b->lexem_type = TOKEN_MULT;
		my_strcpy(lexer_b->lexem, GRAMMAR[4]);
		lexer_b->pos+=1;
		return (SUCCESS);
	}
	return (ERROR);
}

extern bool check_token_non_priority(lexer_b_t *lexer_b)
{
	char token = lexer_b->line[lexer_b->pos];

	switch (token) {
	case '+':
		lexer_b->lexem_type = TOKEN_PLUS;
		my_strcpy(lexer_b->lexem, GRAMMAR[0]);
		lexer_b->pos+=1;
		return (SUCCESS);
	case '-':
		lexer_b->lexem_type = TOKEN_MIN;
		my_strcpy(lexer_b->lexem, GRAMMAR[1]);
		lexer_b->pos+=1;
		return (SUCCESS);
	}
	return (ERROR);
}

extern bool check_token_parenthesis(lexer_b_t *lexer_b)
{
	char token = lexer_b->line[lexer_b->pos];

	switch (token) {
	case '(':
		lexer_b->lexem_type = TOKEN_PAR_L;
		my_strcpy(lexer_b->lexem, GRAMMAR[5]);
		lexer_b->pos+=1;
		return (SUCCESS);
	case ')':
		lexer_b->lexem_type = TOKEN_PAR_R;
		my_strcpy(lexer_b->lexem, GRAMMAR[6]);
		lexer_b->pos+=1;
		return (SUCCESS);
	}
	return (ERROR);
}

extern bool check_token_number(lexer_b_t *lexer_b)
{
	int i = 0;

	if (lexer_b->line[lexer_b->pos] >= '0'
	&& lexer_b->line[lexer_b->pos] <= '9') {
		lexer_b->lexem_type = TOKEN_NB;
		while (lexer_b->pos < my_strlen(lexer_b->line)
		&& lexer_b->line[lexer_b->pos] >= '0'
		&& lexer_b->line[lexer_b->pos] <= '9') {
			lexer_b->lexem[i]
			= lexer_b->line[lexer_b->pos];
			lexer_b->pos+=1;
			i++;
		}
		return (SUCCESS);
	}
	return (ERROR);
}
