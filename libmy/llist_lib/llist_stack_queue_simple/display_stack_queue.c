/*
** EPITECH PROJECT, 2018
** libmy llist
** File description:
** functions that display the stack and the queue
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "../../../include/my_printf.h"
#include "../../../include/llist_stack_queue_simple.h"

static void
	stack_queue_check_type(short type, void *data)
{
	switch (type) {
	case INT_TYPE:
		my_printf("\n%d\n", (int *)data);
		break;
	case CHAR_TYPE:
		my_printf("%s", ((char *)data));
		break;
	}
	return;
}

extern void display_stack_queue(llist_t *list)
{
	llist_t *tmp = NULL;

	for (tmp = list; tmp != NULL; tmp = tmp->next)
		stack_queue_check_type(CHAR_TYPE, tmp->data);
	return;
}
