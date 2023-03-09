/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:33:00 by mjulliat          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/08 15:48:35 by mjulliat         ###   ########.fr       */
=======
/*   Updated: 2023/03/08 21:51:46 by thomas           ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

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

enum e_redirection {
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

enum e_token_quoted {
	E_NONE = 1,
	E_SINGLE = 2,
	E_DOUBLE = 3
};

#endif
