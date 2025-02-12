# Simple Shell

A basic UNIX command-line interpreter built in C. This project is a simple implementation of a shell that can execute commands in both interactive and non-interactive modes.

## 📌 Features
✅ Displays a shell prompt in interactive mode.
✅ Reads and executes single-word commands (e.g., /bin/ls).
✅ Handles errors when commands cannot be found.
✅ Supports non-interactive mode (e.g., echo "/bin/ls" | ./shell).
✅ Properly handles EOF (Ctrl+D) for graceful exit.
✅ Implements child processes to execute commands using execve().

## 🛠 Built-In Commands
Command	Description
exit	Exits the shell
Ctrl+D	Ends the shell (EOF)
## ⚙️ How It Works
The shell displays a prompt (#cisfun$).
It reads user input using getline().
The input is parsed and passed to execve().
If the command is valid, it executes. Otherwise, it prints an error.
The shell waits for the next command.
## 📂 Project Structure
File	Description
main.c	Entry point of the shell
shell.h	Header file with function prototypes
getline.c	Reads user input
exec.c	Executes commands
