/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:04:22 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 17:50:31 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	do_command_pipe(t_pipex *pipex, int cmd_idx)
{
	int		child_status;
	pid_t	cmd_pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (print_gen_error(ERROR_INT_PIPE), RET_ERR);
	cmd_pid = fork();
	if (cmd_pid == -1)
		return (print_gen_error(ERROR_INT_FORK), RET_ERR);
	if (!cmd_pid)
		execute_command(pipex, cmd_idx, p_fd);
	close(p_fd[1]);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[0]);
	if (waitpid(cmd_pid, &child_status, 0) == -1)
		return (print_gen_error(ERROR_CHILD_WAIT), RET_ERR);
	return (handle_child_status(
			child_status,
			pipex->commands[cmd_idx].argv[0]));
}

void	execute_command(t_pipex *pipex, int cmd_idx, int p_fd[2])
{
	char	*cmd_path;

	close(p_fd[0]);
	if (pipex->cmd_count == (unsigned int)cmd_idx + 1)
		(close(p_fd[1]), dup2(pipex->fd_outfile, STDOUT_FILENO));
	else
		(dup2(p_fd[1], STDOUT_FILENO), close(p_fd[1]));
	cmd_path = get_absolute_path(
			pipex->commands[cmd_idx].argv[0],
			pipex->paths
			);
	if (cmd_path == NULL)
		_exit(127);
	if (execve(cmd_path, pipex->commands[cmd_idx].argv, g_envp) == -1)
		_exit(126);
}

int	handle_child_status(int child_status, char *cmd_name)
{
	if (WIFEXITED(child_status))
	{
		if (WEXITSTATUS(child_status) == 127)
			return (print_cmd_not_found_error(cmd_name), RET_ERR);
		else if (WEXITSTATUS(child_status) != 0)
			return (print_gen_error(ERROR_CHILD_EXECUTION), RET_ERR);
	}
	return (RET_OK);
}
