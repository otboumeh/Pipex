/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:11:57 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 16:36:49 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pxb_check_infile(t_pipex_bonus *pipex, char **argv)
{
	if (pipex->here_doc)
		error_msg_bonus(ERR_RDHEREDOC, NULL);
	else
	{
		if (access(argv[1], R_OK) == -1 && !access(argv[1], F_OK))
			pipex_print_msg(argv[1], NO_PERM);
		else
			pipex_print_msg(argv[1], NO_FILE);
	}
}

void	pxb_check_outfile(t_pipex_bonus *pipex, char **argv)
{
	if (pipex->here_doc)
	{
		if (access(argv[5], W_OK) == -1 && !access(argv[5], F_OK))
			pipex_print_msg(argv[5], NO_PERM);
		else
			pipex_print_msg(argv[5], NO_MEMORY);
		return ;
	}
	else
	{
		if (access(argv[pipex->cmd + 2], W_OK) == -1
			&& !access(argv[pipex->cmd + 2], F_OK))
			pipex_print_msg(argv[pipex->cmd + 2], NO_PERM);
		else
			pipex_print_msg(argv[pipex->cmd + 2], NO_MEMORY);
		return ;
	}
}
