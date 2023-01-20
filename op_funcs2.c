#include "monty.h"

/**
 * my_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void my_add(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		/* show relevant error */
		set_error(err_short_stack(line_no, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	my_pop(stack, line_no);
}


/**
 * my_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void my_sub(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(err_short_stack(line_no, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	my_pop(stack, line_no);
}


/**
 * my_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void my_div(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(err_short_stack(line_no, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_error(err_div(line_no));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	my_pop(stack, line_no);
}


/**
 * my_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void my_mul(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(err_short_stack(line_no, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	my_pop(stack, line_no);
}


/**
 * my_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_no: The current working line number of a Monty bytecode file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void my_mod(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error(err_short_stack(line_no, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_error(err_div(line_no));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	my_pop(stack, line_no);
}
