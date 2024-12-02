/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:20:59 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 21:31:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	init_pipex(int argc, char **argv, t_pipex *pipex)
{
	pipex->fd_infile = -1;
	pipex->fd_outfile = -1;
	if (parse_input(argc, argv, pipex) != RET_OK)
		return (RET_ERR);
	pipex->paths = get_paths();
	if (!pipex->paths)
		return (free_pipex(pipex), print_gen_error(ERROR_PATH), RET_ERR);
	pipex->pid_list = malloc(sizeof(int) * (pipex->cmd_count));
	if (!pipex->pid_list)
		return (free_pipex(pipex), print_gen_error(ERROR_INT), RET_ERR);
	return (RET_OK);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->paths)
		free_double_tab(&(pipex->paths));
	if (pipex->fd_infile >= 0)
		close(pipex->fd_infile);
	if (pipex->fd_outfile >= 0)
		close(pipex->fd_outfile);
	free_commands(pipex);
	if (pipex->pid_list)
		free(pipex->pid_list);
	unlink(HERE_DOC_TMP_PATH);
}

void	free_commands(t_pipex *pipex)
{
	size_t	i;

	if (pipex->commands)
	{
		i = 0;
		while (i < pipex->cmd_count)
		{
			if (pipex->commands[i].argv)
				free_double_tab(&(pipex->commands[i].argv));
			i++;
		}
		free(pipex->commands);
		pipex->commands = NULL;
	}
}

void	free_double_tab(char	***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
