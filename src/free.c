/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:20:59 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 19:10:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

void	free_pipex(t_pipex *pipex)
{
	if (pipex->paths)
		free_double_tab(&(pipex->paths));
	if (pipex->fd_infile > 0)
		close(pipex->fd_infile);
	if (pipex->fd_outfile > 0)
		close(pipex->fd_outfile);
	if (pipex->commands)
		free_commands(pipex);
}

void	free_commands(t_pipex *pipex)
{
	while (pipex->commands)
		free_double_tab(pipex->commands++);
	free(pipex->commands);
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
