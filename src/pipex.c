/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 17:05:51 by cpoulain         ###   ########.fr       */
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
	(void)argc;
	g_pname = argv[0];
	g_envp = envp;
	if (parse_input(argc, argv, &pipex) != RET_OK)
		return (EXIT_FAILURE);
	pipex.paths = get_paths();
}
