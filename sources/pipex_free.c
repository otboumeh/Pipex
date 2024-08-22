/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:44:23 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/22 18:55:21 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_array(char	**array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	free_child(t_pipex *pipex)
{
	free_array(pipex->argv_cmd);
	if (pipex->cmd_path)
		free(pipex->cmd_path);
}
