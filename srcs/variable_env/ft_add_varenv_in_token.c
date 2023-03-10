
#include "minishell.h"

void	ft_add_varenv_in_token(t_list_token *token, char **env)
{
	size_t	i;
	size_t	nb_venv;
	char	*name_venv;
	char	**var_env;
	
	var_env = ft_calloc(sizeof(char *), ft_nbr_varenv(token->word) + 1);
	//	TODO check error malloc
	i = 0;
	nb_venv = 0;
	while (token->word[i] != '\0')
	{
		if (token->word[i] == '$')
		{
			i++;
			name_venv = ft_get_name_varenv(&token->word[i]);
			var_env[nb_venv] = ft_getenv(env, name_venv);
			nb_venv++;
			(void) name_venv;
			free(name_venv);
		}
		i++;
	}
	(void) env;
	(void) token;
}
