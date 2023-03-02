/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:33:00 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/02 14:29:46 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//		### BUILTINS ###

# define ECHO	"echo"
# define CD 	"cd"
# define PWD	"pwd"
# define EXPORT	"export"
# define UNSET	"unset"
# define ENV	"env"
# define EXIT	"exit"

//		### REDIRECTION ###

# define D_INFILE	"<"
# define D_OUTFILE	">"
# define D_HEREDOC	"<<"
# define D_APPEND	">>"

//		### PIPE ###

# define PIPE		"|"
#endif
