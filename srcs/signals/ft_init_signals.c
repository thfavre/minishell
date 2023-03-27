
#include "minishell.h"

void ft_init_signals()
{
	struct sigaction sa;
	struct termios	termios;


	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
	sa.sa_handler = ft_handle_signals;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("Error: cannot handle SIGINT");
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		perror("Error: cannot handle SIGQUIT");

	// To be able to close the program with CTRL-Z
	// if (sigaction(SIGTSTP, &sa, NULL) == -1)
	// 	perror("Error: cannot handle SIGTSTP");
}
