#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
int main(int argc, char *argv[]);
char **parse_input(char *input);
int execute_command(char **args);

#endif /* SHELL_H */

