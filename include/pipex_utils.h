/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:29:31 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/27 17:34:33 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

// Includes

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

// Here doc constants

# define HERE_DOC					"here_doc"
# define HERE_DOC_TMP_PATH			"/tmp/tmp-heredoc-pipex"
# define HERE_DOC_PREFIX			"here_doc> "

// Error messages

# define ERROR_MISSING_OPERAND		"%s%s:\tMissing operand\n%s"
# define ERROR_INT					"%s%s:\tInternal error\n%s"
# define ERROR_HERE_DOC_INT			"%s%s:\tInternal error reading here_doc\n%s"
# define ERROR_COMMAND_NOT_FOUND	"%s%s: command not found: %s\n%s"

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

// Structures

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		fd_null;
	int		**pipes;
	pid_t	*pid;
	int		cmd_count;
	int		here_doc;
	char	**envp;
	char	**paths;
}	t_pipex;

// Functions

// Path functions

char	**get_paths(char	**envp);
char	*get_absolute_path(char *command, char **paths);

#endif
