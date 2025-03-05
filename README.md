# Simple Shell Project

## Description
This project implements a simple shell, which mimics the behavior of a traditional Unix shell. It processes commands, executes them, and interacts with the user via the terminal. It is designed to handle common shell operations, including executing system commands, handling command chaining, and managing environment variables.

## Files

- **shell.h**: Contains function prototypes, constants, and struct definitions.
- **shell.c**: Main program file that executes the shell logic.
- **README.md**: This file, describing the project and its functionality.
- **man_1_simple_shell**: The man page for the simple shell.
- **AUTHORS**: List of contributors to the project.

## Compilation
To compile the shell program, run:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell

