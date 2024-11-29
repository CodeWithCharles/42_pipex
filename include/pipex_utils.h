/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:29:31 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 16:47:42 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

// Includes

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// Terminal colors

# define TERM_RESET					"\033[0m"
# define TERM_BLACK					"\033[30m"
# define TERM_RED					"\033[31m"
# define TERM_GREEN					"\033[32m"
# define TERM_YELLOW				"\033[33m"
# define TERM_BLUE					"\033[34m"
# define TERM_MAGENTA				"\033[35m"
# define TERM_CYAN					"\033[36m"
# define TERM_WHITE					"\033[37m"

# define TERM_UP					"\033[1A"
# define TERM_CLEAR_LINE			"\033[2K\r"

// Here doc constants

# define HERE_DOC					"here_doc"
# define HERE_DOC_TMP_PATH			"/tmp/tmp-heredoc-pipex"
# define HERE_DOC_PREFIX			"here_doc> "

// Error messages

# define ERROR_MISSING_OPERAND		"%s%s:\tMissing operand.\n%s"
# define ERROR_INT					"%s%s:\tInternal error.\n%s"
# define ERROR_PATH					"%s%s:\tCould not find path in envp.\n%s"
# define ERROR_HERE_DOC_INT			"%s%s:\tInternal error reading here_doc\n%s"
# define ERROR_CMD_NOT_FOUND		"%s%s:\tcommand not found: %s.\n%s"

// Utils define

# define BUFFER_SIZE				4096

# define RET_OK						0
# define RET_ERR					1

# define PIPE_READ					0
# define PIPE_WRITE					1

// Paths

# define ENVP_PATH					"PATH="
# define ENVP_PATH_SEPARATOR		':'

// Global variable

// Holds the program name
extern char	*g_pname;
extern char	**g_envp;

// Structures

typedef struct s_command
{
	char	**argv;
}	t_command;

typedef struct s_pipex
{
	int			fd_infile;
	int			fd_outfile;
	char		**paths;
	size_t		cmd_count;
	t_command	*commands;
}	t_pipex;

// Functions

// Error functions

void	print_gen_error(const char *error);
void	print_cmd_not_found_error(const char *cmd);

// Free functions

void	free_double_tab(char	***arr);
void	free_pipex(t_pipex *pipex);

// Path functions

char	**get_paths(void);
char	*get_absolute_path(char *command, char **paths);

#endif
