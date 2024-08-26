/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:09 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/22 19:30:39 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex_print_msg(char *param, int error)
{
	if (error == CMD_NOT_FOUND)
		ft_putstr_fd("command not found: ", 2);
	if (error == NO_FILE)
		ft_putstr_fd("no such file or directory: ", 2);
	if (error == NO_PERM)
		ft_putstr_fd("permission denied: ", 2);
	if (error == CMD_FAIL)
		ft_putstr_fd("command failed: ", 2);
	if (error == INV_ARGS)
		ft_putstr_fd("unvalid argc", 2);
	if (error == NO_MEMORY)
		ft_putstr_fd("no memory left on device", 2);
	if (error == DUP_ERR)
		ft_putstr_fd("could not dup fd", 2);
	if (error == PIPE_ERR)
		ft_putstr_fd("could not create pipe", 2);
	if (error == FORK_ERR)
		ft_putstr_fd("could not fork process", 2);
	if (error == NO_PATH)
		ft_putstr_fd("PATH variable is not set", 2);
	if (param && (error == CMD_NOT_FOUND || error == NO_FILE || \
			error == NO_PERM || error == CMD_FAIL))
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}

void	pipex_error_exit(char *param, int error)
{
	pipex_print_msg(param, error);
	exit(error);
}

void	malloc_error_exit(void)
{
	ft_putstr_fd("pipex: could not allocate memory", 2);
	exit (ERR_MALLOC);
}

void	px_error_free(t_pipex *pipex, char *param, int err)
{
	pipex_error_exit(param, err);
	if (err == CMD_NOT_FOUND || err == CMD_FAIL)
		free_child(pipex);
}
