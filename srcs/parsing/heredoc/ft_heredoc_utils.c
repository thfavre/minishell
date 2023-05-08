/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:04:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/10 17:16:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_previous(t_list_token *st)
{
	while (st->next != NULL)
	{
		st->next->previous = st;
		st = st->next;
	}
	while (st->previous != NULL)
		st = st->previous;
}

char	*ft_getname_heredoc(int nb)
{
	char	*name;
	char	*heredoc;
	int		i;

	i = 0;
	heredoc = ".heredoc0\0";
	name = ft_calloc(sizeof(char), ft_strlen(".heredoc0") + 1);
	if (!name)
		return (NULL);
	while (heredoc[i] != '\0')
	{
		name[i] = heredoc[i];
		i++;
	}
	name[i - 1] += nb;
	return (name);
}

char	*ft_getword_heredoc(char *word)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!str)
		return (NULL);
	while (word[i] != '\0')
	{
		str[i] = word[i];
		i++;
	}
	return (str);
}

int	ft_syntax_heredoc(t_list_token *heredoc, t_minishell *ms)
{
	heredoc = heredoc->next;
	while (heredoc != NULL)
	{
		if (heredoc->type == E_PIPE || heredoc->type == E_REDIRECTION)
			return (ft_error_heredoc(ms, 1));
		else if (heredoc->type == E_STRING)
		{
			if (ft_error_eof_heredoc(heredoc->word) == 1)
				return (ft_error_heredoc(ms, 2));
			ms->syntax = 0;
			g_last_exit_status = 0;
			return (0);
		}
		heredoc = heredoc->next;
	}
	if (heredoc == NULL)
		return (ft_error_heredoc(ms, 1));
	return (0);
}

char	*ft_strjoin_heredoc(char *s1, char *s2)
{
	char	*str;
	char	*new_str;

	new_str = NULL;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		str = ft_memcpy(str, s1, ft_strlen(s1));
		free(s1);
	}
	new_str = ft_strjoin(str, s2);
	free(str);
	if (s2 != NULL)
		free(s2);
	return (new_str);
}
