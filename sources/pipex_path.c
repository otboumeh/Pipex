/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:36:22 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/16 16:42:00 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *get_path(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return(envp[i] + 5);
		i++;
	}
	return (NULL);
}
char **split_path(char **envp)
{
	char *full_path;
	char **path_splited;

	full_path = get_path(envp);
		if (!full_path)
			return (1);
	path_splited = ft_split(full_path, ':');
	
	return (path_splited);
}