/*
** EPITECH PROJECT, 2018
** libmy llist
** File description:
** functions that count the node in the stack or the queue
*/

#include <stddef.h>
#include "../../../include/llist_stack_queue_simple.h"

extern unsigned long count_stack_queue(llist_t *list)
{
	llist_t *tmp = NULL;
	unsigned long count_node = 0;

	for (tmp = list; tmp != NULL; tmp = tmp->next)
		count_node += 1;
	return (count_node);
}
