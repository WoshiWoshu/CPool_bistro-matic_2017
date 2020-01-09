/*
** EPITECH PROJECT, 2018
** eval_expr
** File description:
** lexer of the eval_expr
*/

#ifndef LEXER_BISTRO_H
#define LEXER_BISTRO_H

#include <stdbool.h>

extern const int TOKEN_NB;
extern const int TOKEN_PAR_L;
extern const int TOKEN_PAR_R;
extern const int TOKEN_MOD;
extern const int TOKEN_END;

static const int UP = 1;
static const int DOWN = 0;
static const bool SUCCESS = 0;
static const bool ERROR = 1;
static const char GRAMMAR[7][3] = {{'+', DOWN, '\0'}, {'-', DOWN, '\0'},
				{'/', UP, '\0'}, {'%', UP, '\0'},
				{'*', UP, '\0'}, {'(', DOWN, '\0'},
				{')', DOWN, '\0'}};

enum lexem {
	TOKEN_PLUS = 1,
	TOKEN_MIN,
	TOKEN_MULT,
	TOKEN_DIV,
};

typedef struct lexer_b_s lexer_b_t;

struct lexer_b_s {
	int pos;
	int lexem_type;
	char *lexem;
	char *line;
	char **npi_string;
};

extern bool check_token_priority(lexer_b_t *lexer_b);
extern bool check_token_non_priority(lexer_b_t *lexer_b);
extern bool check_token_number(lexer_b_t *lexer_b);
extern bool check_token_parenthesis(lexer_b_t *lexer_b);
extern lexer_b_t initialize_var_lexer(lexer_b_t lexer_b, char *av_1);
extern bool lexer_bistro(lexer_b_t *lexer_b);

#endif /* LEXER_BISTRO_H */
