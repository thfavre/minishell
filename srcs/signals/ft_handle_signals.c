
#include "minishell.h"

void ft_handle_signals(int signo)
{
	if (signo == SIGINT)
	{
		// ft_putstr_fd("(handle sigint start)", 2);
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0); // Clear the user input.
		rl_on_new_line();
		rl_redisplay();
		// ft_putstr_fd("SIGINT )", 2);
		// Terminate any child processes that are currently running.
		//kill(0, SIGTERM);
		g_last_exit_status = 128 + SIGINT;
		// ft_putstr_fd("(handle sigint end)", 2);
	}
	else if (signo == SIGQUIT) // to do nothing with clr-backstlash
	{
		rl_on_new_line();
		rl_redisplay();
		g_last_exit_status = 128 + SIGQUIT;
	}
}
