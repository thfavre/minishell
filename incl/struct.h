/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/27 11:16:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//		### All Data ###

typedef struct s_minishell {
	char			**env;
	char			**path;
	char			**prompt_split;
	int				fd_infile;
	int				fd_outfile;
	int				**fd_pipe;
	struct s_list	*start;
}			t_minishell;

//		### Chain List ###

typedef struct s_list {
	int					id_cmd;
	char				**cmd;
	struct s_minishell	*ms;
	struct s_list		*next;
}						t_list;

#endif
