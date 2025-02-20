#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point for the simple shell program
 * Return: 0 on success, exit status on failure
 */
int main(void)
{
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    char *args[2];  /* Only one word command, so we use two slots: [0] = command, [1] = NULL */
    pid_t pid;
    int status;

    while (1)
    {
        /* Display prompt */
        write(STDOUT_FILENO, "#cisfun$ ", 9);  /* You can change the prompt text here */

        /* Read user input */
        nread = getline(&input, &bufsize, stdin);
        if (nread == -1)  /* Handle EOF (Ctrl+D) */
        {
            free(input);
            exit(0);
        }

        /* Remove the newline character */
        input[nread - 1] = '\0'; 

        /* Split input into arguments (just one word expected) */
        args[0] = input;
        args[1] = NULL;

        /* Create a child process to execute the command */
        pid = fork();
        if (pid == -1)  /* Error occurred with fork */
        {
            perror("Error: fork failed");
            free(input);
            continue;
        }

        if (pid == 0)  /* Child process */
        {
            if (execve(args[0], args, NULL) == -1)  /* Execute command */
            {
                perror("./shell");
                exit(1);
            }
        }
        else  /* Parent process */
        {
            wait(&status);  /* Wait for the child to finish */
        }
    }

    free(input);
    return (0);
}

