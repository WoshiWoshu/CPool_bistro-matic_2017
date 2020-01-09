/*
** EPITECH PROJECT, 2018
** libmy llist
** File description:
** llist simple stack queue header
*/

#ifndef LLIST_STACK_QUEUE_SIMPLE_H
#define LLIST_STACK_QUEUE_SIMPLE_H

#include <stdbool.h>

extern const bool ERROR;

typedef struct llist_s llist_t;

struct llist_s {
	void *data;
	llist_t *next;
	bool empty_set;
};

typedef enum circular_info_e {
	INT_TYPE = 1,
	CHAR_TYPE = 2,
} circular_info_t;

extern llist_t *push_stack(llist_t *stack, void *data);
extern void *pop_stack(llist_t **stack);
extern void display_stack_queue(llist_t *list);
extern unsigned long count_stack_queue(llist_t *list);
extern llist_t *push_queue(llist_t *queue, void *data);
extern void *pop_queue(llist_t **queue);

#endif /* LLIST_STACK_QUEUE_SIMPLE_H */
