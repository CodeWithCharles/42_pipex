/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:18:47 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 12:43:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "libft.h"

int	parse_input(
	int argc,
	char **argv,
	t_pipex *pipex
)
{
	int	here_doc;
	int	out_flags;

	if (argc < 2)
		return (print_gen_error(ERROR_MISSING_ARGS), RET_ERR);
	here_doc = ft_strcmp(argv[1], HERE_DOC) == 0;
	pipex->cmd_count = argc - (3 + here_doc * 2);
	if (argc - (3 + here_doc * 2) < 0)
		return (print_gen_error(ERROR_MISSING_ARGS), RET_ERR);
	out_flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (here_doc)
	{
		if (read_here_doc(argv[2], pipex) != RET_OK)
			return (RET_ERR);
		out_flags = (out_flags & ~O_TRUNC) | O_APPEND;
	}
	else
		pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile < 0)
		return (print_no_such_file_error(argv[1]), RET_ERR);
	pipex->fd_outfile = open (argv[argc - 1], out_flags, 0666);
	if (pipex->fd_outfile < 0)
		return (print_gen_error(ERROR_INT), RET_ERR);
	return (parse_commands(argv + 2 + here_doc * 2, pipex));
}

int	parse_commands(
	char **argv,
	t_pipex *pipex
)
{
	unsigned int	curr_cmd;

	curr_cmd = 0;
	pipex->commands = malloc(sizeof(t_command) * pipex->cmd_count);
	if (!pipex->commands)
		return (free_pipex(pipex), print_gen_error(ERROR_INT), RET_ERR);
	while (curr_cmd < pipex->cmd_count)
	{
		pipex->commands[curr_cmd].argv = ft_split(argv[curr_cmd], ' ');
		if (!pipex->commands[curr_cmd++].argv)
			return (free_pipex(pipex), print_gen_error(ERROR_INT), RET_ERR);
	}
	return (RET_OK);
}
