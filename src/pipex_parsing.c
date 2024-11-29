/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:18:47 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/29 17:32:13 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include "libft.h"

int	parse_input(
	int argc,
	char **argv,
	t_pipex *pipex
)
{
	int	here_doc;

	here_doc = 1;
	if (argc < 2)
		return (print_gen_error(ERROR_MISSING_ARGS), RET_ERR);
	here_doc = ft_strcmp(argv[1], HERE_DOC) == 0;
	pipex->cmd_count = argc - (3 + here_doc);
	if (argc - (3 + here_doc) < 0)
		return (print_gen_error(ERROR_MISSING_ARGS), RET_ERR);
	return (RET_OK);
}
