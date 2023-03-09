
#include "minishell.h"

int	ft_get_infile(t_list_token **pars)
{
	int	fd;

	(*pars) = (*pars)->next;
	while ((*pars)->word[0] == ' ' || (*pars)->word[0] == '\t')
		(*pars) = (*pars)->next;
	fd = open((*pars)->word, O_RDONLY);
	return (fd);
}

int	ft_get_outfile(t_list_token **pars)
{
	int	fd;

	(*pars) = (*pars)->next;
	while ((*pars)->word[0] == ' ' || (*pars)->word[0] == '\t')
		(*pars) = (*pars)->next;
	fd = open((*pars)->word, O_TRUNC | O_CREAT | O_RDWR, 0644);
	return (fd);
}
