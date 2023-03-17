
#include "minishell.h"

void	ft_parse_varenv(t_minishell *ms)
{
	t_list_token	*start;

	start = ms->token;
	while (ms->token != NULL)
	{
		if (ms->token->type == E_STRING && ms->token->quote == E_NONE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				ft_add_varenv_in_token(ms->token, ms->env);
		}
		else if (ms->token->type == E_STRING && ms->token->quote == E_DOUBLE)
		{
			if (ft_token_got_varenv(ms->token->word) == 1)
				ft_replace_varenv(ms->token, ms->env);
		}
		ms->token = ms->token->next;
	}
	ms->token = start;
}

char	*ft_get_name_varenv(char *str)
{
	char	*var_env;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '$' || str[i] == ' ' || str[i] == '\'')
			break ;
		len++;
		i++;
	}
	var_env = ft_calloc(sizeof(char), len + 1);
	if (!var_env)
		return (NULL);
	i = 0;
	while (i < len)
	{
		var_env[i] = str[i];
		i++;
	}	
	return (var_env);
}

int	ft_token_got_varenv(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbr_varenv(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			count++;
		i++;
	}
	return (count);
}
