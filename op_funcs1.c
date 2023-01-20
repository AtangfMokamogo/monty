#include "monty.h"

/**
  * my_push - pushes an element to the stack
  * @stack : pointer to the top node of the linked list stack_t.
  * @line_no: current line on the opened monty bytecode file
  */
void my_push(stack_t **stack, unsigned int line_no)
{
	stack_t *temp, *new_s;
	int x;
	new_s = malloc(sizeof(stack_t));

	if (new_s == NULL)
	{
		set_error(err_malloc());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_error(err_no_data(line_no));
		return;
	}

	for (x = 0; op_toks[1][1]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_error(err_no_data(line_no));
			return;
		}
	}
	new_s->n = atoi(op_toks[1]);

	if (stack_mode(*stack) == STACK)
	{
		temp = (*stack)->next;
		new_s->prev = *stack;
		new_s->next = temp;
		if (temp)
			temp->prev = new_s;
		(*stack)->next = new_s;
	}
	else
	{
		temp = *stack;
		while (temp->next)
		{
			temp = temp->next;
		}
		new_s->prev = temp;
		new_s->next = NULL;
		temp->next = new_s;
	}
}


/**
 * my_pall - prints all the values on the stack,
 * 	starting from the top of the stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 */
void my_pall(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_no;
}


/**
 * my_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 */
void my_pint(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		set_error(err_pint(line_no));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * my_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 */
void my_pop(stack_t **stack, unsigned int line_no)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_error(err_pop(line_no));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * my_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void my_swap(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(err_short_stack(line_no, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
