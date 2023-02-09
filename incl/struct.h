/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/09 17:50:16 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//		### All Data ###

typedef struct s_minishell {
	char	**env;
	char	**path;
	struct s_list	*start;
	int		nb_cmd;
	int		fd_infile;
	int		fd_outfile;
	int		*fd_pipe[2];
}			t_minishell;


//		### Chain List ###

typedef struct s_list {
	int					id_cmd;
	char				**cmd;
	struct s_minishell	*ms;
	struct s_list		*next;
}						t_list;

#endif
