/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 15:26:38 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

char	*g_pname;
char	**g_envp;

int	main(int argc, char **argv, char **envp)
{
	t_pipex			pipex;
	int				ret_code;
	unsigned int	i;

	ret_code = RET_OK;
	g_pname = argv[0];
	g_envp = envp;
	if (init_pipex(argc, argv, &pipex) != RET_OK)
		return (EXIT_FAILURE);
	dup2(pipex.fd_infile, STDIN_FILENO);
	i = 1;
	while (i < pipex.cmd_count)
	{
		if (do_command_pipe(&pipex, i - 1) != RET_OK)
			ret_code = RET_ERR;
		i++;
	}
	dup2(pipex.fd_outfile, STDOUT_FILENO);
	ret_code = do_command_pipe(&pipex, i);
	free_pipex(&pipex);
	return (ret_code);
}
