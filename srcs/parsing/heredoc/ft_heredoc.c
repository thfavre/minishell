/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:54:46 by mjulliat          #+#    #+#             */
/*   Updated: 2023/04/05 12:10:03 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_minishell *ms)
{
	t_list_token	*st;
	int				i;

	i = 0;
	st = ms->token;
	ft_add_previous(st);
	while (st != NULL)
	{
		if (st->next == NULL && st->previous == NULL && st->red == E_HEREDOC)
		{
			ft_error_heredoc(ms, 1);
			break ;
		}
		if (st->next != NULL && st->red == E_HEREDOC)
			ft_heredoc_found(&st, ms, &i);
		if (st->next == NULL)
			break ;
		st = st->next;
	}
	while (st->previous != NULL)
		st = st->previous;
	ms->token = st;
}

void	ft_heredoc_found(t_list_token **st, t_minishell *ms, int *i)
{
	if ((*st)->previous == NULL)
	{
		(*i)++;
		(*st) = ft_get_heredoc((*st), ms, (*i));
	}
	else
	{
		(*i)++;
		(*st) = (*st)->previous;
		(*st)->next = ft_get_heredoc((*st)->next, ms, (*i));
	}
}

t_list_token	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms, int i)
{
	t_list_token	*new;
	t_list_token	*tmp;
	char			*name;

	if (ft_syntax_heredoc(heredoc, ms) == 1)
		return (heredoc);
	name = ft_getname_heredoc(i);
	new = ft_lstnew_token(ft_getword_heredoc("<"));
	new->previous = heredoc->previous;
	ft_lstadd_back_token(&new, ft_lstnew_token(ft_getword_heredoc(name)));
	while (heredoc != NULL)
	{
		if (heredoc->type == E_STRING)
		{
			ft_eof_found(heredoc, new, name);
			break ;
		}
		tmp = heredoc;
		heredoc = heredoc->next;
		free(tmp);
	}
	free(name);
	return (new);
}

void	ft_eof_found(t_list_token *heredoc, t_list_token *new, char *name)
{
	t_list_token	*tmp;

	ft_open_heredoc(heredoc, name);
	tmp = heredoc;
	if (heredoc->next != NULL)
		ft_lstadd_back_token(&(*new).next, heredoc->next);
	free(tmp);
}

void	ft_open_heredoc(t_list_token *heredoc, char *name)
{
	int		fd_heredoc;
	char	*line;
	char	*nl;
	char	*all;

	all = NULL;
	fd_heredoc = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	line = readline("> ");
	while (line != NULL)
	{
		if (ft_strcmp(heredoc->word, line) == 0)
			break ;
		nl = ft_strjoin(line, "\n");
		free(line);
		all = ft_strjoin(all, nl);
		free(nl);
		line = readline("> ");
	}
	if (all != NULL)
		ft_putstr_fd(all, fd_heredoc);
	close(fd_heredoc);
}
