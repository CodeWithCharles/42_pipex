/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:49:17 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 15:21:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	read_here_doc(
	const char *limiter,
	t_pipex *pipex
)
{
	char	*line;

	pipex->fd_infile = open(HERE_DOC_TMP_PATH,
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_infile < 0)
		return (print_gen_error(ERROR_HERE_DOC_OPEN_TMP), RET_ERR);
	ft_putstr_fd(HERE_DOC_PREFIX, STDIN_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter) - 1))
	{
		ft_putstr_fd(line, pipex->fd_infile);
		(ft_putstr_fd(HERE_DOC_PREFIX, STDIN_FILENO), free(line));
		line = get_next_line(STDIN_FILENO);
	}
	(free(line), close(pipex->fd_infile));
	pipex->fd_infile = open(HERE_DOC_TMP_PATH, O_RDONLY, 0666);
	if (pipex->fd_infile < 0)
		return (print_gen_error(ERROR_HERE_DOC_OPEN_TMP), RET_ERR);
	return (RET_OK);
}
