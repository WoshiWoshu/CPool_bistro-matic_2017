/*
** EPITECH PROJECT, 2018
** do-op
** File description:
**
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/do_op.h"

long long do_op(char *data_1, char *data_2, char data_type)
{
	long long result = 0;

	if (data_type == '*')
		result = multiplication(data_1, data_2, result);
	if (data_type == '/')
		result = division(data_1, data_2, result);
	if (data_type == '-')
		result = substraction(data_1, data_2, result);
	if (data_type == '+')
		result = addition(data_1, data_2, result);
	if (data_type == '%')
		result = modulo(data_1, data_2, result);
	return (result);
}
