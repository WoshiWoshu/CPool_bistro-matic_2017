/*
** EPITECH PROJECT, 2018
** llist list
** File description:
** functions that pop, push and print the stack
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../include/llist_stack_queue_simple.h"

const bool ERROR = 1;

static llist_t *initialize_stack(llist_t *stack, void *data)
{
	stack = malloc(sizeof(*stack));
	stack->data = data;
	stack->next = NULL;
	stack->empty_set = false;
	return (stack);
}

extern llist_t *push_stack(llist_t *stack, void *data)
{
	llist_t *node = NULL;
	llist_t *tmp = stack;

	if (stack == NULL)
		stack = initialize_stack(stack, data);
	else {
		node = malloc(sizeof(*node));
		node->data = data;
		node->next = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (stack);
}

extern void *pop_stack(llist_t **stack)
{
	llist_t *free_node = *stack;
	llist_t *browse_node = *stack;
	void *get_data_node = NULL;

	if (count_stack_queue(*stack) == 1)
		free_node->empty_set = true;
	if (*stack == NULL)
		return ((void *)ERROR);
	while (free_node->next != NULL)
		free_node = free_node->next;
	get_data_node = free_node->data;
	if (count_stack_queue(*stack) > 1) {
		while (browse_node->next->next != NULL)
			browse_node = browse_node->next;
		browse_node->next = NULL;
	}
	free(free_node);
	if (free_node->empty_set == true)
		*stack = NULL;
	return (get_data_node);
}
