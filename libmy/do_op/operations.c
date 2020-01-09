/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** operations
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

long long addition(char *data_1, char *data_2, long long result)
{
	long long x = my_getnbr(data_1);
	long long y = my_getnbr(data_2);

	result = x + y;
	return (result);
}

long long modulo(char *data_1, char *data_2, long long result)
{
	long long x = my_getnbr(data_1);
	long long y = my_getnbr(data_2);

	if (data_2[0] == '0') {
		write(2, "Stop: division by zero", 22);
		exit(84);
	}
	result = x % y;
	return (result);
}

long long division(char *data_1, char *data_2, long long result)
{
	long long x = my_getnbr(data_1);
	long long y = my_getnbr(data_2);

	if (data_2[0] == '0') {
		write(2, "Stop: division by zero", 22);
		exit(84);
	}
	result = x / y;
	return (result);
}

long long substraction(char *data_1, char *data_2, long long result)
{
	long long x = my_getnbr(data_1);
	long long y = my_getnbr(data_2);

	result = x - y;
	return (result);
}

long long multiplication(char *data_1, char *data_2, long long result)
{
	long long x = my_getnbr(data_1);
	long long y = my_getnbr(data_2);

	result = x * y;
	return (result);
}
