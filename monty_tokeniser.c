#include "monty.h"


/**
 * my_tow - takes a string and separates its words  into individual tokens
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each token
 */

char **my_tow(char *str, char *delims)
{
	char **tokens = NULL;
	int tc, tok_len, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	tc = word_count(str, delims);

	if (tc == 0)
		return (NULL);
	tokens = malloc((tc + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (i < tc)
	{
		tok_len = word_length(str, delims);
		if (delim(*str, delims))
			str = next_word(str, delims);

		tokens[i] = malloc((tok_len + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(tokens[i]);
			}
			free(tokens);
			return (NULL);
		}
		n = 0;
		while (n < tok_len)
		{
			tokens[i][n] = *(str + n);
			n++;
		}
		tokens[i][n] = '\0';
		str = next_word(str, delims);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}


/**
 * delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */
int delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}


/**
 * word_length - gets the word length of current token in string @str
 *
 * @str: string 
 * @delims: delimitors to use to delimit words
 *
 * Return: length of current token
 */
int word_length(char *str, char *delims)
{
	int S_tok = 0, delay = 1, x = 0;

	while (*(str + x))
	{
		if (delim(str[x], delims))
			delay = 1;
		else if (delay)
		{
			S_tok++;
		}
		if (S_tok > 0 && delim(str[x], delims))
			break;
		x++;
	}
	return (S_tok);
}


/**
 * word_count - gets the count of tokens in a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the token count of the string
 */
int word_count(char *str, char *delims)
{
	int C_tok = 0, delay = 1, x = 0;

	while (*(str + x))
	{
		if (delim(str[x], delims))
			delay = 1;
		else if (delay)
		{
			delay = 0;
			C_tok++;
		}
		C_tok++;
	}
	return (C_tok);
}


/**
 * next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */
char *next_word(char *str, char *delims)
{
	int delay = 0;
	int x = 0;

	while (*(str + x))
	{
		if (delim(str[x], delims))
			delay = 1;
		else if (delay)
			break;
		x++;
	}
	return (str + x);
}
