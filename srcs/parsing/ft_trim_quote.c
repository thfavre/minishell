
#include "minishell.h"
char	*ft_remove_quote(char **str);

void	ft_trim_quote(t_minishell *ms)
{
	t_list_token	*trim_quote;

	trim_quote = ms->token;
	while (trim_quote != NULL)
	{
		if (trim_quote->quote == E_SINGLE || trim_quote->quote == E_DOUBLE)
			trim_quote->word = ft_remove_quote(&trim_quote->word);
		trim_quote = trim_quote->next;
	}
}

char	*ft_remove_quote(char **str)
{
	char	*trim;
	char	*cpy;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	cpy = (*str);
	trim = ft_calloc(sizeof(char), ft_strlen((*str)) - 2 + 1);
	if (!trim)
		return (NULL);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '\'' || cpy[i] == '"')
			i++;
		else
		{
			trim[j] = cpy[i];
			i++;
			j++;
		}
	}
	free(*str);
	return (trim);
}

