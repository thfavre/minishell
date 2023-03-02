
#include "minishell.h"

void ft_init_signals()
{
	struct sigaction sa;

	sa.sa_handler = ft_handle_signals;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("Error: cannot handle SIGINT");

	// To be able to close the program with CTRL-Z
	if (sigaction(SIGTSTP, &sa, NULL) == -1)
		perror("Error: cannot handle SIGTSTP");
}
