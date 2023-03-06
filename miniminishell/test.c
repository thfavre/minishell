# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <signal.h>


int main()
{

	char *cmd1[] = {"/bin/ls", "-la", NULL};
	char *cmd2[] = {"/usr/bin/grep", "out", NULL};
	// char **cmd[2] = {cmd1, cmd2};

	int fd[2];
	pipe(fd);


	pid_t pid1 = fork();
	if (pid1 == 0) //child 1
	{
		// This is the child process.
		close(fd[0]); // close the read
		dup2(fd[1], 1);
		// Execute the first command in the pipeline.
		execvp(cmd1[0], cmd1);
		close(fd[1]);
	}
	else // parent
	{
		// from parent child
		// Fork another child process to run the second command in the pipeline.
		pid_t pid2 = fork();
		if (pid2 == 0) // child 2
		{
			// This is the child process.
			// close(fd[1]); // write


			dup2(fd[0], 0); // Redirect standard input to the read end of the pipe.
			// close(fd[0]);
			// Execute the second command in the pipeline.
			execvp(cmd2[0], cmd2);
		}
		else
		{
			// Close both ends of the pipe.
			close(fd[0]);
			close(fd[1]);

			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

	// pid_t pid1 = fork();
	// if (pid1 != 0)
	// {
	// 	// This is the child process.
	// 	// execute the command
	// 	execvp("ls", NULL);

	// }
	// else
	// {
	// 	dup2(fd, 1);
	// 	printf("test");
	// 	write(1, "A", 4);
	// }

