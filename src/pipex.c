/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/28 16:51:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "libft.h"

char	*g_pname = NULL;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		ret_code;

	g_pname = argv[0];
	pipex.envp = envp;
	pipex.null_fd = open("/dev/null", O_RDWR, 0666);
	if (pipex.null_fd < 0)
		return (EXIT_FAILURE);
	if (parse_input(argc, argv, &pipex) != RET_OK)
		return (EXIT_FAILURE);
	pipex.paths = get_paths(envp);
}
