/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:24 by thomas            #+#    #+#             */
/*   Updated: 2023/03/07 23:33:17 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd);

void ft_execute(t_minishell *ms)
{
	int fd_pipe_read_tmp = 0;
	int fd_pipe[2];

	struct s_list_cmd *cmd = ms->cmd;

	while (cmd)
	{
		pipe(fd_pipe);
		pid_t fork_pid = fork();
		if (fork_pid == 0) // child
		{
			dup2(fd_pipe_read_tmp, 0); // read

			if (!cmd->next) // if last command
			{
				close(fd_pipe[1]);
				fd_pipe[1] = 1;
			}

			if (cmd->fd_read > 1) // TODO change to 0 and // TODO rename fd_read to file_read_fd? And set to 0 if defaut, -1 error, else file fd
			{
				close(fd_pipe[0]);
				fd_pipe[0] = cmd->fd_read;
			}

			if (cmd->fd_write > 1) // TODO same
			{
				close(fd_pipe[1]);
				fd_pipe[1] = cmd->fd_write;
			}

			dup2(fd_pipe[1], 1); // write
			ft_run_cmd(ms, cmd);
			// execvp(cmd->cmd, cmd->option);
		}
		// parent
		close(fd_pipe[1]);
		fd_pipe_read_tmp = fd_pipe[0];

		cmd = cmd->next;
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	while (waitpid(-1, NULL, WUNTRACED) == -1)
		;
}

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd)
{
	// if builtin command execute the command with the correct function
	if (0)
	{

	}
	// if it is an external command, run it with execve
	else
	{
		execvp(cmd->cmd, cmd->option);
		// ft_setenv(ms, "TEST_KEY", "TEST_VALUE", 1);
		// ft_setenv(ms, "TEST_KEY2", "TEST_VALUE2", 1);
		// ft_unsetenv(ms->env, "TEST_KEY2");
		// ft_unsetenv(ms->env, "PATH");
		// ft_env(ms->env);
		// printf("->%s|\n", ft_getenv(ms->env, "TEST_KEY"));
	}
	(void)cmd;
	(void)ms;


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
