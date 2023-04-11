/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:33:21 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 14:39:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_sorted(char **arr, int n);

void	ft_print_export(char **env)
{
	int	env_size;

	env_size = 0;
	while (env[env_size])
		env_size++;
	print_sorted(env, env_size);
}

static char	**sort_strings(char **arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
				swap_strings(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (arr);
}

static void	print_sorted(char **arr, int n)
{
	int		i;
	int		equal_pos;
	char	**sorted_arr;
	char	**copy_arr;

	copy_arr = malloc(sizeof(*arr) * (n + 1));
	i = -1;
	while (arr[++i])
		copy_arr[i] = ft_strdup(arr[i]);
	copy_arr[i] = NULL;
	sorted_arr = sort_strings(copy_arr, n);
	i = -1;
	while (++i < n)
	{
		equal_pos = 0;
		if (ft_strchr(sorted_arr[i], '='))
			equal_pos = ft_strchr(sorted_arr[i], '=') - sorted_arr[i];
		printf("declare -x ");
		if (equal_pos != 0)
			printf("%.*s\"%s\"\n", equal_pos + 1, sorted_arr[i],
				sorted_arr[i] + equal_pos + 1);
		else
			printf("%s\n", sorted_arr[i]);
	}
	ft_free_env(copy_arr);
}
