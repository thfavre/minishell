#include <stdio.h>     // For input/output functions such as printf
#include <stdlib.h>    // For functions such as malloc and free
#include <string.h>    // For string manipulation functions such as strtok and strcmp
#include <unistd.h>    // For functions such as fork and execve
#include <sys/wait.h>  // For functions such as waitpid and WIFEXITED
#include <readline/readline.h>  // For the readline function
#include <readline/history.h>   // For the command history functions such as add_history
#include <signal.h>    // For signal handling functions such as sigaction
#include <fcntl.h>     // For file I/O functions such as open and close
#include <dirent.h>    // For directory manipulation functions such as opendir and readdir
#include <sys/stat.h>  // For file status functions such as stat and fstat
#include <errno.h>     // For error handling functions such as perror and strerror
#include <termios.h>   // For terminal I/O functions such as tcsetattr and tcgetattr
#include <curses.h>    // For terminal I/O functions such as tgetent and tputs

#define MAX_INPUT_LENGTH 1024

void handle_signal(int signo)
{
	// This function handles signals sent to the shell, such as Ctrl+C.
	// In this case, we simply print a new line to make the shell more user-friendly.
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);  // Clear the user input.
		rl_on_new_line();
		rl_redisplay();
	}
}

int main()
{
	char *input;
	char *args[256];
	pid_t pid;
	int status;

	// Set up signal handling for the shell.
	struct sigaction sa;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1) {
		perror("Error: cannot handle SIGINT");
	}

	while(1) {
		// Read user input from the command line using readline.
		input = readline("$ ");
		if (input == NULL || input[0] == '\0') {
			continue;
		}

		// Add the user input to the command history.
		add_history(input);

		// Parse the user input into separate arguments.
		// ex. : args = {"ls", "-la", "srcs", NULL}
		char *token = strtok(input, " ");
		int i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		// If the user entered "exit", then exit the shell.
		if (strcmp(args[0], "exit") == 0) {
			printf("Goodbye!\n");
			free(input);
			break;
		}

		// Fork a new process to execute the command.
		pid = fork();
		if (pid == 0) {
			// This is the child process.

			// Execute the command.
			if (execvp(args[0], args) == -1) {
				perror("Error");
			}
			exit(EXIT_FAILURE);
		} else if (pid < 0) {
			// There was an error forking.
			perror("Error");
		} else {
			// This is the parent process.

			// Wait for the child process to finish executing.
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status)); // If the child process exited normally, WIFEXITED(status) will return true. If the child process was terminated by a signal, WIFSIGNALED(status) will return true.
		}

		// Free the user input.
		free(input);
	}


	// Clear the command history.
	// rl_clear_history();

	return 0;
}
