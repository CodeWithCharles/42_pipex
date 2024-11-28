/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:16:24 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/28 16:14:19 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tester.h"

int	test_get_paths(char	**envp)
{
	char	**good;
	int		i;
	int		p_test;

	print_test_header("get_paths");
	p_test = 0;
	i = 0;
	good = get_paths(envp);
	if (good != NULL)
		while (good[i] != NULL)
			i++;
	p_test += print_test_result((i > 0 && good), "get_paths good input", NULL);
	free_double_tab(&good);
	return (p_test);
}
