
#include "minishell.h"

void	*ft_calloc(size_t nbyte, size_t size)
{
	void	*cal;

	cal = malloc(nbyte * size);
	if (!cal)
		return (NULL);
	ft_memset(cal, 0, nbyte * size);
	return (cal);
}

void	ft_freesplit(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
}
