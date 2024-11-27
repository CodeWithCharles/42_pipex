/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:48 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/27 17:42:01 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_utils.h"
#include "../include/libft.h"

char	*g_pname = NULL;

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		ret_code;
	char	*path;
	char	*cmd_test;
	int i = 0;
	char	**cmd_args;

	(void)argc;
	cmd_test = "ls -l";
	ret_code = RET_ERR;
	g_pname = argv[0];
	pipex.paths = get_paths(envp);
	while (pipex.paths[i])
		ft_printf("%s\n", pipex.paths[i++]);
	pipex.envp = envp;
	cmd_args = ft_split(cmd_test, ' ');
	path = get_absolute_path(cmd_args[0], pipex.paths);
	if (path)
		ft_printf("\nTest : found command %s at %s.", cmd_test, path);
	else
		ft_printf("\nTest : could not find command %s in envp.", cmd_test);
	return (ret_code);
}
