#include "shell.h"
 
/**
 * execute_command - Executes user input as a command
 * @command: The command string
 * @argv: Argument vector for handling exit
 */
void execute_command(char *command, char **argv)
{
    char *args[100]; /* Array to store command arguments */
    char *token;
    int i = 0;
    pid_t pid;
    int status;

    token = strtok(command, " \n");
    while (token)
    {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "exit") == 0)
    {
        free(command);
        exit(0);
    }

    pid = fork();
    if (pid == 0) /* Child process */
    {
        if (execve(args[0], args, environ) == -1)
            perror(argv[0]);
        exit(127);
    }
    else if (pid > 0) /* Parent process */
        wait(&status);
    else
        perror("fork");
}

