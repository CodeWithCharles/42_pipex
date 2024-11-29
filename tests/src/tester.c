/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:11:25 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 16:50:18 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_tester.h"

char	*g_pname;
char	*g_envp;

int	main(int argc, char **argv, char **envp)
{
	int	p_test;

	p_test = 0;
	(void)argc;
	g_pname = argv[0];
	g_envp = envp;
	p_test += test_get_paths();
	p_test += test_get_absolute_path();
	print_test_footer(p_test);
	return (0);
}

int	print_test_result(int result, char *test_name, char *error)
{
	if (!result)
	{
		ft_printf("%s%s :%s\t%s - %sKO%s\n", TERM_YELLOW, g_pname, TERM_WHITE,
			test_name, TERM_RED, TERM_RESET);
		if (error)
			ft_printf("\t%sError : %s%s\n", TERM_RED, error, TERM_RESET);
	}
	else
		ft_printf("%s%s :%s\t%s - %sOK%s\n", TERM_YELLOW, g_pname, TERM_WHITE,
			test_name, TERM_GREEN, TERM_RESET);
	return (result);
}

void	print_test_header(char *test_name)
{
	ft_printf("\n\t\t%s---- %sTesting : %s%s ----%s\n\n",
		TERM_MAGENTA, TERM_YELLOW, test_name, TERM_MAGENTA, TERM_RESET);
}

void	print_test_footer(int result)
{
	ft_printf("\n\t\t%s---- %s report ----%s\n",
		TERM_MAGENTA, g_pname, TERM_RESET);
	ft_printf("\t\t   %s%d%s tests passed.%s\n",
		TERM_YELLOW, result, TERM_GREEN, TERM_RESET);
	ft_printf("\t\t%s---- %s report ----%s\n\n",
		TERM_MAGENTA, g_pname, TERM_RESET);
}
