#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(int ac, char **av, char **env)
{
	char	*ls[] = {"/bin/ls", "-la", NULL};
	char	*grep[] = {"/usr/bin/grep", "14", NULL};
	char	*wc[] = {"usr/bin/wc", "-l", NULL};

	char	**cmd[]	= {ls, grep, wc};

	int	i = 0;
	int	fd_pipe[2];
	int	pid_fork[10000];
	pipe(fd_pipe);
	while (i < 3)
	{
		pid_fork[i] = fork();
		if (pid_fork[i] == 0)
		{
			if (i % 2 == 0)
			{
				dup2(fd_pipe[1], 1);
				close(fd_pipe[0]);
				execve(cmd[i][0], cmd[i], NULL);
			}
			else
			{
				dup2(fd_pipe[0], 0);
				close(fd_pipe[1]);
				execve(cmd[i][0], cmd[i], NULL);
			}
		}
		i++;	
	}
	i = 0;
	while (i < 3)
	{
		waitpid(pid_fork[i], NULL, 0);
		i++;
	}
}
