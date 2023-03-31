
#include "minishell.h"

t_list_token	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms);
int				ft_syntax_heredoc(t_list_token *heredoc, t_minishell *ms);
char			*ft_getword_heredoc(char *word);
void	ft_open_heredoc(t_list_token *heredoc);
int	ft_strcmp_heredoc(char *s1, char *s2);
int				ft_error_eof_heredoc(char *str);
int				ft_error_heredoc(t_minishell *ms, int code_error);

void	ft_heredoc(t_minishell *ms)
{
	t_list_token	*start;

	start = ms->token;
	while (start->next != NULL)
	{
		start->next->previous = start;
		start = start->next;
	}
	while (start->previous != NULL)
		start = start->previous;
	while (start != NULL)
	{
		if (start->next == NULL && start->previous == NULL && start->redirection == E_HEREDOC)
		{
			ft_error_heredoc(ms, 1);
			break ;
		}
		if (start->next != NULL && start->redirection == E_HEREDOC)
		{
			if (start->previous == NULL)
				start = ft_get_heredoc(start, ms);
			else
			{
				start = start->previous;
				start->next = ft_get_heredoc(start->next, ms);
			}
		}
		if (start->next == NULL)
			break ;
		start = start->next;
	}
	while (start->previous != NULL)
		start = start->previous;
	ms->token = start;
}

t_list_token	*ft_get_heredoc(t_list_token *heredoc, t_minishell *ms)
{
	t_list_token	*new;
	t_list_token	*tmp;

	if (ft_syntax_heredoc(heredoc, ms) == 1)
		return (heredoc);
	new = ft_lstnew_token(ft_getword_heredoc("<"));
	new->previous = heredoc->previous;
	ft_lstadd_back_token(&new, ft_lstnew_token(ft_getword_heredoc(".heredoc")));
	while (heredoc != NULL)
	{
		if (heredoc->type == E_STRING)
		{
			ft_open_heredoc(heredoc);
			tmp = heredoc;
			ft_lstadd_back_token(&new->next, heredoc->next);
			free(tmp);
			break ;
		}
		tmp = heredoc;
		heredoc = heredoc->next;
		free(tmp);
	}
	return (new);
}

void	ft_open_heredoc(t_list_token *heredoc)
{
	int		fd_heredoc;
	char	*line;
	char	*all;
	char	*name;

	all = NULL;
	name = ".heredoc";
	fd_heredoc = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp_heredoc(heredoc->word, line) == 0)
			break ;
		all = ft_strjoin(all, line);
		free(line);
		line = get_next_line(0);
	}
	if (all != NULL)
		ft_putstr_fd(all, fd_heredoc);
	close(fd_heredoc);
}

int	ft_strcmp_heredoc(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		if (s2[i + 1] == '\n')
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
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
			last_exit_status = 0;
			return (0);
		}
		heredoc = heredoc->next;
	}
	if (heredoc == NULL)
		return (ft_error_heredoc(ms, 1));
	return (0);
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

int	ft_error_eof_heredoc(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int	ft_error_heredoc(t_minishell *ms, int code_error)
{
	if (code_error == 1)
		ft_putstr_fd("minishell: parse error near <<\n", 2);
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token", 2);
		ft_putstr_fd(" `newline'\n", 1);
	}
	ms->syntax = 1;
	last_exit_status = 258;
	return (1);
}
