
#include "minishell.h"

char	*ft_getword_redirection(char **str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_redirection(*str, c) + 1);
	while (**str == c)
	{
		word[i] = **str;
		i++;
		(*str)++;
	}
	return (word);
}

char	*ft_getword_space(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword_space(*str) + 1);
	while (**str == ' ' || **str == '\t')
	{
		word[i] = (**str);
		i++;
		(*str)++;
	}
	return (word);
}

char	*ft_getword(char **str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), ft_lenword(*str) + 1);
	while (**str != '\0')
	{
		if (**str == '\'' || **str == '"')
			ft_getword_in_quote(str, word, &i ,**str);
		else if (**str == '<' || **str == '>' || **str == '|' || **str == ' ')
			break ;
		else 
		{
			word[i] = (**str);
			(*str)++;
			i++;
		}
	}
	return (word);
}

void	ft_getword_in_quote(char **str, char *word, int *i, char c)
{
	while (**str != '\0')
	{
		word[*i] = **str;
		(*str)++;
		(*i)++;
		if (**str == c)
		{
			word[*i] = **str;
			(*str)++;
			(*i)++;
			break ;
		}
	}
}
