#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: The number of arguments passed to the program
 * @argv: The array of arguments
 * Return: 0 on success, exit status on failure
 */
int main(int argc, char *argv[])
{
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    char **args;

    /* Display the prompt and read input */
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&input, &bufsize, stdin);
        if (nread == -1)
        {
            free(input);
            return (0);
        }

        input[nread - 1] = '\0';  /* Remove newline */
        args = parse_input(input); /* Parse the input */

        if (args == NULL)
        {
            free(input);
            continue;
        }

        if (execute_command(args) == -1)
        {
            free(input);
            free(args);
            return (1);
        }

        free(input);
        free(args);
    }

    return (0);
}

