/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:03:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 11:11:26 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//		### All Data ###

typedef struct s_minishell {
	char			**env;
	char			**path;
	int				fd_infile;
	int				fd_outfile;
	int				**fd_pipe;
	struct s_list	*token;
}					t_minishell;

//		### Chain List Token ###

typedef struct s_list {
	char			*word;
	struct s_list	*next;
}					t_list;

#endif
