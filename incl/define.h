/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:33:00 by mjulliat          #+#    #+#             */
/*   Updated: 2023/03/08 14:54:39 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//		### ENUM TOKEN TYPE ###

enum token_type {
	E_BUILTINS = 1,
	E_REDIRECTION = 2,
	E_PIPE = 3,
	E_SPACE = 4,
	E_STRING = 5
};

//		### DEFINE BUILTINS ###

# define D_ECHO		"echo"
# define D_CD 		"cd"
# define D_PWD		"pwd"
# define D_EXPORT	"export"
# define D_UNSET	"unset"
# define D_ENV		"env"
# define D_EXIT		"exit"

//		### DEFINE REDIRECTION ###

# define D_INFILE	"<"
# define D_OUTFILE	">"
# define D_HEREDOC	"<<"
# define D_APPEND	">>"

//		### ENUM REDIRECTION ###

enum redirection {
	E_INFILE = 1,
	E_OUTFILE = 2,
	E_HEREDOC = 3,
	E_APPEND = 4
};

//		### DEFINE PIPE & QUOTE ###

# define D_PIPE		"|"
# define D_SQUOTE	"'"
# define D_DQUOTE	"\""

//		### ENUM QUOTE ###

enum token_quoted {
	E_NONE = 1,
	E_SINGLE = 2,
	E_DOUBLE = 3
};

#endif
