/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:12:30 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/28 16:40:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tester.h"

int	test_get_absolute_path(void)
{
	const char	*str = "/home/cpoulain/bin:/usr/local/sbin:/usr/local/bin:/usr" \
		"/sbin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char		**paths;
	int			p_test;
	char		*res;

	print_test_header("get_absolute_path");
	p_test = 0;
	paths = ft_split(str, ':');
	res = get_absolute_path("ls", paths);
	p_test += print_test_result((res != NULL),
			"get_absolute_path valid cmd", "Could not find command in path.");
	if (res)
		free(res);
	res = get_absolute_path("efwd", paths);
	p_test += print_test_result((res == NULL),
			"get_absolute_path invalid cmd", "Found invalid command.");
	if (res)
		free(res);
	free_double_tab(&paths);
	return (p_test);
}
