
#include "minishell.h"

void	ft_replace_varenv(t_list_token *token, char **env)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;

	var_env = ft_calloc(sizeof(char *), ft_nbr_varenv(token->word) + 1);
	// TODO check error malloc
	i = 0;
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			i++;
			name_venv = ft_get_name_varenv(&token->word[i]);
			var_env[nb_venv] = ft_getenv(env, name_venv);
			if (var_env[nb_venv] == NULL)
				break ;
			nb_venv++;
			free(name_venv);
		}
		else
			i++;
	}
	token->word = ft_get_new_word(token->word, var_env);
	free(var_env);
}

char	*ft_get_new_word(char *word, char **var_env)
{
	char	*new_word;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	save;

	i = 0;
	j = 0;
	k = 0;
	new_word = ft_calloc(sizeof(char), ft_len_new_word(word, var_env) + 1);
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			save = i + 1;
			i = 0;
			if (var_env[k] != NULL)
			{
				while (var_env[k][i] != '\0') // TODO need to replace by strcat
				{
					new_word[j] = var_env[k][i];
					i++;
					j++;
				}
			}
			k++;
			i = save;
			i++;
			while (word[i] != '"' && word[i] != ' ' && word[i] != '$' && word[i] != '\0')
				i++;
		}
		else	// TODO need to replace by strcat
		{
			new_word[j] = word[i];
			i++;
			j++;
		}
	}
	free(word);
	return (new_word);
}

int	ft_len_new_word(char *word, char **var_env)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			if (var_env[j] != NULL)
				count += ft_strlen(var_env[j]);
			j++;
			i++;
			while (word[i] != '"' && word[i] != ' ' \
					&& word[i] != '$' && word[i] != '\0')
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}
