#include "monty.h"

char **op_toks = NULL;

/**
 * main - the entry point for Monty interpreter
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */

int main(int argc, char **argv)
{
	/* initialise file variable to null */
	FILE *file_doc = NULL;
	int exit_cd = EXIT_SUCCESS;

	if (argc != 2)
	{
		/* return error no arguments provided */
	}

	/* open file and read line by line */
	file_doc = fopen(argv[1], "r");

	if (file_doc == NULL)
	{
		/* return error in opening file */
	}

	/* run commands from file */
	exit_cd = execute_file(file_doc);

	fclose(file_doc);
	return (exit_cd);
}
