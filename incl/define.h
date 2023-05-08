/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:29 by thomas            #+#    #+#             */
/*   Updated: 2023/04/11 15:41:39 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define DEBUG 0

//		### COLORS ###

# define GREEN_BOLD		"\e[1;32m"
# define RED_BOLD		"\e[1;31m"
# define YELLOW_BOLD	"\e[1;33m"
# define PURPLE_BOLD	"\e[1;35m"
# define CYAN_BOLD		"\e[1;36m"
# define COLOR_RESET	"\e[0m"
# define PROMPT_COLOR	CYAN_BOLD

//		### ENUM TOKEN TYPE ###

enum e_token_type {
	E_BUILTINS = 11,
	E_REDIRECTION = 12,
	E_PIPE = 13,
	E_SPACE = 14,
	E_STRING = 15
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

enum e_redirection {
	E_INFILE = 20,
	E_OUTFILE = 21,
	E_HEREDOC = 22,
	E_APPEND = 23,
	E_NORED = 24
};

//		### DEFINE PIPE & QUOTE ###

# define D_PIPE		"|"
# define D_SQUOTE	"'"
# define D_DQUOTE	"\""

//		### ENUM QUOTE ###

enum e_token_quoted {
	E_NONE = 31,
	E_SINGLE = 32,
	E_DOUBLE = 33
};

#endif
