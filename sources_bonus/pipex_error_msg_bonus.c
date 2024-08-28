/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_msg_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:51:27 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 18:51:06 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"


void	error_msg_bonus(int err, char *param)
{
	ft_putstr_fd("pipex: ", 2);
	if (err == INV_ARGS)
	{
		ft_putstr_fd("invalid arguments, use: ", 2);
		ft_putstr_fd("./pipex infile cmd1 cmd2 ... cmdn outfile or ", 2);
		ft_putstr_fd("./pipex here\\_doc LIMITER cmd1 cmd2 outfile\n", 2);
	}
	else if (err == ERR_HEREDOC)
		ft_putstr_fd("error opening here_doc\n", 2);
	else if (err == ERR_RDHEREDOC)
		ft_putstr_fd("error reading from here_doc\n", 2);
	else if (err == ERR_HEREDOC_EOF)
		ft_putstr_fd("here_doc terminated with end-of-file, expected ", 2);
	if (err == ERR_HEREDOC_EOF)
	{
		ft_putstr_fd(param, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	perror_exit_bonus(int err, char *param)
{
	error_msg_bonus(err, param);
	exit (err);
}

void	cmd_not_found_bonus(t_pipex_bonus *pipex)
{
	pipex_print_msg(pipex->argv_cmd[0], CMD_NOT_FOUND);
	free_array(pipex->argv_cmd);
}

void	cmd_fail_exit_bonus(t_pipex_bonus *pipex)
{
	pipex_print_msg(pipex->argv_cmd[0], CMD_FAIL);
	free(pipex->cmd_path);
	free_array(pipex->argv_cmd);
	exit (CMD_FAIL);
}
