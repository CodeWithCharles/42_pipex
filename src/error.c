/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:08:39 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/27 18:44:09 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

void	cmd_not_found(t_pipex pipex, char *cmd)
{
	(void)pipex;
	(void)cmd;
}

void	print_gen_error(const char *error)
{
	fd_printf(STDERROR, error, TERM_RED, g_pname, TERM_RESET);
}
