
#include "minishell.h"

void	ft_join_token(t_list_token *lst)
{
	t_list_token	*tmp;
	char			*new_word;
	int				i;
	int				j;

	while (lst != NULL)
	{
		if (lst->next != NULL && *lst->word != ' ' && *lst->next->word != ' ')
		{
			i = 0;
			j = 0;
			new_word = ft_calloc(sizeof(char), \
				ft_strlen(lst->word) + ft_strlen(lst->next->word) + 1);
			//	TODO malloc error
			while (lst->word[i] != '\0')
			{
				new_word[j] = lst->word[i];
				i++;
				j++;
			}
			i = 0;
			while (lst->next->word[i] != '\0')
			{
				new_word[j] = lst->next->word[i];
				i++;
				j++;
			}
			free(lst->word);
			lst->word = new_word;
			tmp = lst->next;
			lst->next = tmp->next;
			free(tmp->word);
			free(tmp);
		}
		else
			lst = lst->next;
	}
}
