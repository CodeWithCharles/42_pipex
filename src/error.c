/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:08:39 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 16:57:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

void	print_cmd_not_found_error(const char *cmd)
{
	fd_printf(STDERR_FILENO, ERROR_CMD_NOT_FOUND,
		TERM_RED,
		g_pname,
		cmd,
		TERM_RESET
		);
}

void	print_gen_error(const char *error)
{
	fd_printf(STDERR_FILENO, error,
		TERM_RED,
		g_pname,
		TERM_RESET
		);
}
