/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:36:22 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/22 19:32:43 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**split_path(char **envp)
{
	char	*full_path;
	char	**path_splited;

	full_path = get_path(envp);
	if (!full_path)
		return (1);
	path_splited = ft_split(full_path, ':');
	return (path_splited);
}

char	*get_cmd_path(char	*cmd, char **paths_array)
{
	char	*tmp;
	char	*cmd_path;

	while (*paths_array)
	{
		tmp = ft_strjoin(*paths_array, "/");
		if (!tmp)
			malloc_error_exit();
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (!cmd_path)
			malloc_error_exit();
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		cmd_path = NULL;
		paths_array++;
	}
	return (NULL);
}
