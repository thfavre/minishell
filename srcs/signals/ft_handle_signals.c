
#include "minishell.h"

void ft_handle_signals(int signo)
{



	if (signo == SIGINT)
	{
		// {
		printf("HERE %d\n", WIFEXITED(g_last_exit_status));


		if (WIFEXITED(g_last_exit_status)) //checks whether the child process terminated normally, that is, by calling the exit() function or by returning from the main() function. If this is true, the macro returns a non-zero value.
		{
			ft_putstr_fd("\n", 1);
			rl_replace_line("", 0); // Clear the user input.
			// if (g_last_exit_status != 130)
			rl_on_new_line();
			rl_redisplay();
			printf("111\n");

			// g_last_exit_status = WEXITSTATUS(g_last_exit_status); // extracts the exit code from the exit status. This macro should only be called if WIFEXITED() returned true, otherwise the behavior is undefined.

		}
		else if ((WIFSIGNALED(g_last_exit_status)))
		{
			// g_last_exit_status = WTERMSIG(g_last_exit_status);
			// g_last_exit_status = 128 + SIGINT;
			printf("222\n");
		}
		// ft_putstr_fd("(handle sigint start)", 2);
		// ft_putstr_fd("\n", 1);
		// rl_replace_line("", 0); // Clear the user input.
		// if (g_last_exit_status != 130)
		// rl_on_new_line();
		// rl_redisplay();
		// ft_putstr_fd("SIGINT )", 2);
		// Terminate any child processes that are currently running.
		//kill(0, SIGTERM);
		// ft_putstr_fd("(handle sigint end)", 2);
	}
	else if (signo == SIGQUIT) // to do nothing with clr-backstlash
	{
		rl_on_new_line();
		rl_redisplay();
		g_last_exit_status = 128 + SIGQUIT;
	}
}
