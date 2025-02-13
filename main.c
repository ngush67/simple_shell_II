#include "shell.h"
 
/**
 * main - Entry point of our simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;

    while (1)
    {
        if (isatty(STDIN_FILENO)) /* Check if interactive mode */
            write(STDOUT_FILENO, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);
        if (read == -1) /* Handles Ctrl+D (EOF) */
        {
            free(line);
            write(STDOUT_FILENO, "\n", 1);
            exit(0);
        }

        line[strcspn(line, "\n")] = '\0'; /* Remove newline character */

        if (strlen(line) == 0) /* Ignore empty command */
            continue;

        if (strcmp(line, "exit") == 0) /* Check for "exit" command */
        {
            free(line);
            exit(0);
        }

        pid = fork();
        if (pid == 0) /* Child process */
        {
            char *args[2];  
            args[0] = line;
            args[1] = NULL;

            if (execve(line, args, environ) == -1)
                perror("./shell");
            exit(127);
        }
        else if (pid > 0) /* Parent process */
            wait(&status);
        else
            perror("fork");
    }

    free(line);
    return (0);
}

