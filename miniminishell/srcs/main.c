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
		// all up was the same as with no pipes

		// Parse the user input to identify the commands that should be piped together.
		char *cmd1[256], *cmd2[256];
		int pipe_index = 0;
		while (args[pipe_index] != '|')
			pipe_index++;
		args[pipe_index] = NULL;
		cmd1 = args;
		cmd2 = args[pipe_index];
		printf("DEBUG (cmd1:%s), (cmd2:%s)\n", cmd1, cmd2);



		// Create a pipe.
		int fd[2];
		if (pipe(fd) == -1) {
			perror("Error: pipe creation failed");
			continue;
		}

		// Fork a child process to run the first command in the pipeline.
		pid_t pid1 = fork();
		if (pid1 == 0) {
			// This is the child process.
			// Redirect the standard output to the write end of the pipe.
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);

			// Execute the first command in the pipeline.
			execvp(cmd1[0], cmd1);
			perror("Error: command execution failed");
			exit(EXIT_FAILURE);
		} else if (pid1 < 0) {
			// There was an error forking.
			perror("Error: fork failed");
			continue;
		}

		// Fork another child process to run the second command in the pipeline.
		pid_t pid2 = fork();
		if (pid2 == 0) {
			// This is the child process.
			// Redirect the standard input to the read end of the pipe.
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);

			// Execute the second command in the pipeline.
			execvp(cmd2[0], cmd2);
			perror("Error: command execution failed");
			exit(EXIT_FAILURE);
		} else if (pid2 < 0) {
			// There was an error forking.
			perror("Error: fork failed");
			continue;
		}

		// Close both ends of the pipe.
		close(fd[0]);
		close(fd[1]);

		// Wait for both child processes to finish executing.
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);


		// Free the user input.
		free(input);
	}


	// Clear the command history.
	// rl_clear_history();

	return 0;
}
