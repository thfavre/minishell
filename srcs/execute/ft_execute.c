
#include "minishell.h"


// struc s_cmd
// {

// 	int read_fd;
// 	int write_fd;
// 	int *pipe_fds[2];
// }


void ft_execute(t_minishell *ms)
{
	(void)ms;
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

}
