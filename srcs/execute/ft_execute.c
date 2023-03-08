/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:39:24 by thomas            #+#    #+#             */
/*   Updated: 2023/03/08 17:39:34 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd);

void ft_execute(t_minishell *ms)
{
	int fd_pipe_read_tmp = 0;
	int fd_pipe[2];

	struct s_list_cmd *cmd = ms->cmd;
	// if only one command => No need of a fork for ONLY the builtins ^^

	while (cmd)
	{
		pipe(fd_pipe);
		pid_t fork_pid = fork();
		if (fork_pid == 0) // child
		{
			// read
			if (cmd->fd_read > 3)
				close(fd_pipe[0]);
			else
				cmd->fd_read = fd_pipe_read_tmp;
			dup2(cmd->fd_read, 0);

			// write
			if (cmd->fd_write > 3)
				close(fd_pipe[1]);
			else if (!cmd->next)
				cmd->fd_write = 1;
			else
				cmd->fd_write = fd_pipe[1];
			dup2(cmd->fd_write, 1); // write

			ft_run_cmd(ms, cmd);
			exit(0);
			// execvp(cmd->cmd, cmd->option);
		}
		// parent
		close(fd_pipe[1]);
		fd_pipe_read_tmp = fd_pipe[0];

		cmd = cmd->next;
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	// while (waitpid(-1, NULL, WUNTRACED) == -1)
	// 	;
	// wait for all child processes to finish
	while (waitpid(-1, NULL, 0) > 0)
		;
}

void	ft_execute_builtin(char **env, struct s_list_cmd *cmd)
{
	char	filepath[256];
	char	**splited_path;
	int		i;

	splited_path = ft_getsplitedpath(env);
	i = 0;
	while (splited_path[i] != NULL)
	{

		// or create a filepath variable with malloc?
		strcpy(filepath, splited_path[i]); // TODO repalce with ft version
		strcat(filepath, "/"); // TODO repalce with ft version
		strcat(filepath, cmd->cmd); // TODO repalce with ft version
		if (access(filepath, X_OK) == 0)
		{
			ft_freesplit(splited_path);
			execve(filepath, cmd->option, env);
		}
		i++;
	}
}

void	ft_run_cmd(t_minishell *ms, struct s_list_cmd *cmd)
{
	// if builtin command execute the command with the correct function
	// if (ft_strcmp("pwd", cmd->cmd) == 0)
	// {
	// 	filepath
	// 	access(, X_OK)
	// }
	// if it is an external command, run it with execve
	if (ft_strcmp("pwd", cmd->cmd) == 0)
		ft_pwd();
	else if (ft_strcmp("env", cmd->cmd) == 0)
		ft_env(ms->env);
	else if (ft_strcmp("cd", cmd->cmd) == 0)
		ft_cd(cmd->option);
	else
		ft_execute_builtin(ms->env, cmd);
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
