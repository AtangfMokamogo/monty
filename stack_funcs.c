#include "monty.h"

/**
 * stack_init - Initializes a stack_t stack with beginning stack
 *             and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE. Otherwise - EXIT_SUCCESS.
 */
int stack_init(stack_t **stack)
{
	stack_t *stc;

	stc = malloc(sizeof(stack_t));
	if (stc == NULL)
		/* return memory allocation error */
		return (err_malloc());

	stc->n = STACK;
	stc->prev = NULL;
	stc->next = NULL;

	*stack = stc;

	return (EXIT_SUCCESS);
}


/**
 * stack_free - Frees a stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void stack_free(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * stack_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int stack_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
