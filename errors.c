#include "monty.h"

/**
 * err_op_unknown - Prints unknown instruction error messages.
 * @opcode: Opcode thast causing the error.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_op_unknown(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * err_no_data - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_no_data(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_file_open - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_file_open(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * err_malloc - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}


/**
 * usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_use(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
