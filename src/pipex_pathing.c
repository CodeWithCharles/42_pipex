/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pathing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:45:23 by cpoulain          #+#    #+#             */
/*   Updated: 2024/11/28 15:15:39 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex_utils.h"

char	**get_paths(char	**envp)
{
	char	*path;

	while (*envp)
	{
		if (ft_strncmp(*envp, ENVP_PATH, sizeof(ENVP_PATH) - 1) != 0)
		{
			++envp;
			continue ;
		}
		path = (*envp) + sizeof(ENVP_PATH) - 1;
		return (ft_split(path, ENVP_PATH_SEPARATOR));
	}
	return (NULL);
}

char	*get_absolute_path(char *command, char **paths)
{
	char	*res;
	size_t	command_size;
	size_t	path_size;

	command_size = ft_strlen(command);
	while (*paths)
	{
		path_size = ft_strlen(*paths);
		res = malloc((path_size + command_size + 2));
		if (!res)
			return (NULL);
		ft_memcpy(res, *paths, path_size);
		ft_memcpy(res + path_size + 1, command, command_size);
		res[path_size] = '/';
		res[command_size + path_size + 1] = '\0';
		if (access(res, F_OK) == 0)
			return (res);
		free(res);
		++paths;
	}
	return (NULL);
}
