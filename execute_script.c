#include "monty.h"

/**
  * execute_file - runs the monty bytecode script.
  * @file_doc: Descriptor for an open monty file.
  *
  * Return: EXIT_SUCCESS on success, and error on failure
  */

int execute_file(FILE *file_doc)
{
	/* pointer to respective operation functions on stack */
	void (*stack_func)(stack_t**, unsigned int);

	stack_t *stack = NULL;

	/* pointer to monty bytecode line in file_doc */
	char *f_line = NULL;

	unsigned int line_no = 0, pre_token_len;
	size_t line_len = 0, exit_cd = EXIT_SUCCESS;

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&f_line, &line_len, file_doc) != -1)
	{
		line_no++;
		op_toks = my_tow(f_line, DELIMS);
		if (op_toks == NULL)
		{
			if (empty_line(f_line, DELIMS))
				continue;
			stack_free(&stack);

			return (err_malloc());
		}

		/* check for comments */
		else if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}

		stack_func = get_op_func(op_toks[0]);
		if (stack_func == NULL)
		{
			stack_free(&stack);
			exit_cd = err_op_unknown(op_toks[0], line_no);
			free_tokens();
			break;
		}
		pre_token_len = token_arr_len();

		stack_func(&stack, line_no);

		if (token_arr_len() != pre_token_len)
		{
			if (op_toks && op_toks[pre_token_len])
				exit_cd = atoi(op_toks[pre_token_len]);
			else
				exit_cd = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	stack_free(&stack);

	if (f_line && *f_line == 0)
	{
		free(f_line);
		return (err_malloc());
	}

	free(f_line);
	return (exit_cd);
}


/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{"sub", my_sub},
		{"div", my_div},
		{"mul", my_mul},
		{"mod", my_mod},
		{"pchar", my_pchar},
		{"pstr", my_pstring},
		{"rotl", my_rotl},
		{"rotr", my_rotr},
		{"stack", my_stack},
		{"queue", my_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}


/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}


/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}
