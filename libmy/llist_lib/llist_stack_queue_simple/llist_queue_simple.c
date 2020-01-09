/*
** EPITECH PROJECT, 2018
** libmy llist
** File description:
** functions that push pop and count the queue
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../include/llist_stack_queue_simple.h"

static llist_t *initialize_queue(llist_t *queue, void *data)
{
	queue = malloc(sizeof(*queue));
	queue->data = data;
	queue->next = NULL;
	queue->empty_set = false;
	return (queue);
}

extern llist_t *push_queue(llist_t *queue, void *data)
{
	llist_t *node = NULL;
	llist_t *tmp = queue;

	if (queue == NULL)
		queue = initialize_queue(queue, data);
	else {
		node = malloc(sizeof(*node));
		node->data = data;
		node->next = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (queue);
}

extern void *pop_queue(llist_t **queue)
{
	llist_t *free_node = *queue;
	void *get_data_node = free_node->data;

	*queue = free_node->next;
	free(free_node);
	if (count_stack_queue(*queue) == 0)
		*queue = NULL;
	return (get_data_node);
}
