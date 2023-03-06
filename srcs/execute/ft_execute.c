
//#include "minishell.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <signal.h>
// struc s_cmd
// {

// 	int read_fd;
// 	int write_fd;
// 	int *pipe_fds[2];
// }


//The longer answer is that in bash, commands in a pipeline are each executed in a subshell. Since cd is a shell builtin, it only affects the shell it's executed in. If you cd within a subshell, the effect will disappear when the subshell exits.
void	ft_cd_command(char* path)
{
	if (path == NULL)
		chdir(getenv("HOME"));
	else if (chdir(path) != 0)
		perror("chdir() error");
}


void	ft_pwd_command(void)
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	printf("%s\n", cwd);
}


int ft_lst_len(char **lst)
{
	int i = 0;
	while (lst[i])
		i++;
	return i;

}


int main()
{
	char *cmd1[] = {"ls", "-la", NULL};
	char *cmd2[] = {"head", "-n 3", NULL};
	char *cmd3[] = {"grep","13", NULL};
	char *cmd4[] = {"wc", NULL};
	char **commands[] = {cmd1, cmd2, cmd3,cmd4, NULL};

	int i = 0;
	int fd_tmp = 0;
	int fd_pipe[2];


	while (commands[i])
	{
		pipe(fd_pipe);
		pid_t fork_pid = fork();
		if (fork_pid == 0) //child
		{
			dup2(fd_tmp, 0); // read


			// 	fd_pipe[1] = 1;
			if (!commands[i+1])
				// close pipe 1
				fd_pipe[1] = 1;

			// if (cmd->fd_write > 1)
			// 	//close pipe 1?
			// 	fd_pipe[1] = cmd->fd_write;


			// if (cmd->fd_read > 0)
			// 	//close pipe 0?
			// 	fd_pipe[0] = cmd->fd_read;


			dup2(fd_pipe[1], 1); // write
			execvp(commands[i][0], commands[i]);
			close(fd_pipe[1]);
			close(fd_tmp);
			break;
		}
		// parent
		close(fd_pipe[1]);
		fd_tmp = fd_pipe[0];
		i++;
	}
	close(fd_pipe[0]);
}



// int main()
// {
//
// 	char *cmd1[] = {"/bin/ls", "-la", NULL};
// 	char *cmd2[] = {"/usr/bin/grep", "13", NULL};

// 	char **cmd[2] = {cmd1, cmd2};

// 	int fd[2];
// 	pipe(fd);

// 	int i = 0;
// 	while (i < 2)
//	{
//		if (!fork())
//		{
//			//child
//			if (i == 0)
//			{
//				//dup2(fd[0], 0);
//				dup2(fd[1], 1); //fd[1] write
//			}
//			else
//			{
//				dup2(fd[0], 0);
//				// close(fd[1]);
//			}
//			execve(cmd[i][0], cmd[i], NULL);
//		}
//		else
//		{
//			// parent
//			i++;
//		}
//	}
//	close(fd[0]);
//	close(fd[1]);
//	while (waitpid(-1, NULL, WUNTRACED) == -1)
//		;
//}



	//(void)ms;
	// t_list_cmd	current_cmd;

	// current_cmd = ms->cmd;
	// while (current_cmd)
	// {
	// 	// execute the command in a fork
	// 	pid_t pid = fork();
	// 	if (pid == 0) // This is the child process.
	// 	{
	// 		dup2(ms->cmd->read_fd, 0);
	// 		dup2(ms->cmd->write_fd, 1);
	// 		close(ms->cmd->fd[0]);
	// 		close(ms->cmd->fd[1]);
	// 		// check...
	// 		execvp(current_cmd->cmd, current_cmd->options);
	// 		break;
	// 	}
	// 	// parent process
	// 	close(ms->cmd->fd[0]);
	// 	close(ms->cmd->fd[1]);

	// 	// Wait for both child processes to finish executing.
	// 	waitpid(pid, NULL, 0);
	// 	//waitpid(pid2, NULL, 0);

	// 	current_cmd = current_cmd->next;
	// }

// }
