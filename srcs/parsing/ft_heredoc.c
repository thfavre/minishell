
#include "minishell.h"
t_list_token	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms);
int				ft_syntax_heredoc(t_list_token *heredoc, t_minishell *ms);
void			ft_error_heredoc(t_minishell *ms);

void	ft_heredoc(t_minishell *ms)
{
	t_list_token	*start;

	start = ms->token;
	while (start != NULL)
	{
		if (start->next == NULL && start->previous == NULL)
		{
			ft_error_heredoc(ms);
			break ;
		}
		if (start->next != NULL && start->redirection == E_HEREDOC)
			start = ft_get_heredoc(start, ms);
		if (start->next != NULL)
			start->next->previous = start;
		if (start->next == NULL)
			break ;
		start = start->next;
	}
	while (start->previous != NULL)
		start = start->previous;
	ms->token = start;
	ft_print_list_token(ms->token);
}

t_list_token	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms)
{
	t_list_token	*new;
	t_list_token	*tmp;

	if (ft_syntax_heredoc(heredoc, ms) == 1)
		return (heredoc);
	new = ft_lstnew_token("<");
	new->previous = heredoc->previous;
	ft_lstadd_back_token(&new, ft_lstnew_token(".heredoc"));
	while (heredoc != NULL)
	{
		if (heredoc->type == E_STRING)
		{
			tmp = heredoc;
			new->next->next = heredoc->next;
			free(tmp);
			break ;
		}
		tmp = heredoc;
		heredoc = heredoc->next;
		free(tmp);
	}
	return (new);
}

int	ft_syntax_heredoc(t_list_token *heredoc, t_minishell *ms)
{
	heredoc = heredoc->next;
	while (heredoc != NULL)
	{
		if (heredoc->type == E_PIPE || heredoc->type == E_REDIRECTION)
		{
			ft_error_heredoc(ms);
			return (1);
		}
		else if (heredoc->type == E_STRING)
		{
			ms->syntax = 0;
			last_exit_status = 0;
			return (0);
		}
		heredoc = heredoc->next;
	}
	if (heredoc == NULL)
	{
		ft_error_heredoc(ms);
		return (1);
	}
	return (0);
}

void	ft_error_heredoc(t_minishell *ms)
{
	ft_putstr_fd("minishell: parse error near <<\n", 1);
	ms->syntax = 1;
	last_exit_status = 258;
}
