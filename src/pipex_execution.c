/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:04:22 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 15:33:57 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	do_command_pipe(t_pipex *pipex, int cmd_idx)
{
	pid_t	cmd_pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (print_gen_error(ERROR_INT_PIPE), RET_ERR);
	cmd_pid = fork();
	if (cmd_pid == -1)
		return (print_gen_error(ERROR_INT_FORK), RET_ERR);
	if (!cmd_pid)
	{
		close(p_fd[0]);
		if (pipex->cmd_count == (unsigned int)cmd_idx + 1)
			(close(p_fd[1]), dup2(pipex->fd_outfile, STDOUT_FILENO));
		else
			dup2(p_fd[1], STDOUT_FILENO);
		execute_command(pipex, cmd_idx);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
	}
	return (RET_OK);
}

void	execute_command(t_pipex *pipex, int cmd_idx)
{
	char	*cmd_path;

	cmd_path = get_absolute_path(
			pipex->commands[cmd_idx].argv[0],
			pipex->paths
			);
	if (execve(cmd_path, pipex->commands[cmd_idx].argv, g_envp) == -1)
		print_cmd_not_found_error(pipex->commands[cmd_idx].argv[0]);
}
