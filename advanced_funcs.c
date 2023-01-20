#include "monty.h"

/**
 * my_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_no;
}


/**
 * my_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_rotr(stack_t **stack, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_no;
}


/**
 * my_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_stack(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = STACK;
	(void)line_no;
}


/**
 * my_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 */
void my_queue(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = QUEUE;
	(void)line_no;
}
