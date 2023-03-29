
#include "minishell.h"

void ft_handle_signals(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0); // Clear the user input.
		rl_on_new_line();
		rl_redisplay();
		// Terminate any child processes that are currently running.
		//kill(0, SIGTERM);
		last_exit_status = 128 + SIGINT;
	}
	else if (signo == SIGQUIT) // to do nothing with clr-backstlash
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
