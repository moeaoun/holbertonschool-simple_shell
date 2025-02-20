#include "shell.h"

/**
 * parse_input - Tokenizes the input string into command and arguments
 * @input: The input string to be tokenized
 * Return: Array of tokens (command + arguments)
 */
char **parse_input(char *input)
{
    char **tokens;
    char *token;
    int i = 0;

    tokens = malloc(64 * sizeof(char *));
    if (tokens == NULL)
    {
        perror("Error allocating memory");
        return (NULL);
    }

    token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;  /* Null-terminate the array */
    return (tokens);
}

