
#include "minishell.h"

void ft_execute(t_minishell *ms)
{
	// if only one command => No need of a fork for ONLY the builtins ^^
	if (ms->cmd->cmd != NULL)
	{
		if (ms->cmd->next == NULL)
			ft_execute_cmd(ms);
		else
			ft_execute_cmds(ms);
	}
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
