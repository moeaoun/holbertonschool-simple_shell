#include "shell.h"

/**
 * execute_command - Executes a command by creating a child process
 * @args: The arguments (command and its parameters)
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("Error: fork failed");
        return (-1);
    }
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("Error: execve failed");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
    return (0);
}

