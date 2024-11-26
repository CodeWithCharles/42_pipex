/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/27 18:53:41 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "libft.h"

char	*g_pname = NULL;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		ret_code;

	(void)argc;
	ret_code = RET_OK;
	g_pname = argv[0] + 2;
	pipex.envp = envp;
	pipex.paths = get_paths(envp);
	if (!pipex.paths)
		return (free_pipex(&pipex), print_gen_error(ERROR_PATH), RET_ERR);
	pipex.argv = argv;
	free_double_tab(&(pipex.paths));
	free_pipex(&pipex);
	return (RET_OK);
}
