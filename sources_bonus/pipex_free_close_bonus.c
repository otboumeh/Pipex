/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_close_bonus                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:21:52 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 18:50:01 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pxb_close_pipes(t_pipex_bonus *pipex)
{
	int	i;

	i = 0;
	while (i < ((pipex->cmd - 1) * 2))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	free_parent_bonus(t_pipex_bonus *pipex)
{
	free (pipex->pipe);
	free_array(pipex->paths);
	free (pipex->pid);
}

void	free_parent_closefd_bonus(t_pipex_bonus *pipex)
{
	int	i;

	pxb_close_pipes(pipex);
	i = 0;
	while (i < pipex->cmd)
	{
		waitpid(pipex->pid[i], NULL, 0);
		i++;
	}
	close(pipex->input_fd);
	close(pipex->output_fd);
	free_parent_bonus(pipex);
	if (pipex->here_doc)
		unlink ("/tmp/.here_doc");
}
