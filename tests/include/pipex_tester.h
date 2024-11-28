/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:48:16 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/28 15:33:46 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TESTER_H
# define PIPEX_TESTER_H

# include "libft.h"
# include "pipex_utils.h"

// Test priting

int		print_test_result(int result, char *test_name, char *error);
void	print_test_footer(int result);
void	print_test_header(char *test_name);

// Pathing tests

int		test_get_paths(char	**envp);

#endif
