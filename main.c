#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Argument count
 * @argv: Argument vector
 * 
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    (void)argc; /* Avoid unused parameter warning */
    
    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Interactive mode */
            write(1, "($) ", 4);

        read = getline(&line, &len, stdin);
        if (read == -1) /* EOF (Ctrl+D) or error */
        {
            free(line);
            exit(0);
        }

        execute_command(line, argv); /* Call function to execute */
    }

    free(line);
    return (0);
}

