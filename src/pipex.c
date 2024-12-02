/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/12/02 12:50:12 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "libft.h"

char	*g_pname;
char	**g_envp;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		ret_code;

	(void)ret_code;
	ret_code = RET_OK;
	g_pname = argv[0];
	g_envp = envp;
	if (init_pipex(argc, argv, &pipex) != RET_OK)
		return (EXIT_FAILURE);
	free_pipex(&pipex);
	return (RET_OK);
}
