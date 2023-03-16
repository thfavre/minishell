
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
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	trim = ft_calloc(sizeof(char), ft_strlen(*str) + 1);
	while (str[0][i] != '\0')
	{
		if (str[0][i] == '"' || str[0][i] == '\'')
		{
			c = str[0][i];
			i++;
			while (str[0][i] != '\0' && str[0][i] != c)
			{
				trim[j] = str[0][i];
				i++;
				j++;
			}
			i++;
		}
		else
		{
			trim[j] = str[0][i];
			i++;
			j++;
		}
	}
	free(*str);
	return (trim);
}
