/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:47:06 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 19:54:32 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	first_child_bonus(t_pipex_bonus *pipex, char **argv, char **envp)
{
	if (pipex->input_fd < 0)
	{
		pxb_check_infile(pipex, argv);
		return ;
	}
	if (dup2(pipex->pipe[1], STDOUT_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	pxb_close_pipes(pipex);
	if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	if (pipex->here_doc)
		pipex->argv_cmd = ft_split(argv[3], ' ');
	else
		pipex->argv_cmd = ft_split(argv[2], ' ');
	if (!pipex->argv_cmd)
		malloc_error_exit();
	pipex->cmd_path = get_cmd_path(pipex->argv_cmd[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		cmd_not_found_bonus(pipex);
		return ;
	}
	if (execve(pipex->cmd_path, pipex->argv_cmd, envp) == -1)
		cmd_fail_exit_bonus(pipex);
}

void	middle_child_bonus(t_pipex_bonus *pipex,
			char **argv, char **envp, int i)
{
	if (dup2(pipex->pipe[(i - 1) * 2], STDIN_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	if (dup2(pipex->pipe[(i + 1) * 2 - 1], STDOUT_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	pxb_close_pipes(pipex);
	pipex->argv_cmd = ft_split(argv[i + 2], ' ');
	if (!pipex->argv_cmd)
		malloc_error_exit();
	pipex->cmd_path = get_cmd_path(pipex->argv_cmd[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		cmd_not_found_bonus(pipex);
		return ;
	}
	if (execve(pipex->cmd_path, pipex->argv_cmd, envp) == -1)
		cmd_fail_exit_bonus(pipex);
}

void	last_child_bonus(t_pipex_bonus *pipex, char **argv, char **envp)
{
	if (pipex->output_fd < 0)
	{
		pxb_check_outfile(pipex, argv);
		return ;
	}
	if (dup2(pipex->pipe[(pipex->cmd - 2) * 2], STDIN_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	pxb_close_pipes(pipex);
	if (dup2(pipex->output_fd, STDOUT_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	if (pipex->here_doc)
		pipex->argv_cmd = ft_split(argv[4], ' ');
	else
		pipex->argv_cmd = ft_split(argv[pipex->cmd + 1], ' ');
	if (!pipex->argv_cmd)
		malloc_error_exit();
	pipex->cmd_path = get_cmd_path(pipex->argv_cmd[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		cmd_not_found_bonus(pipex);
		return ;
	}
	if (execve(pipex->cmd_path, pipex->argv_cmd, envp) == -1)
		cmd_fail_exit_bonus(pipex);
}

void	child_selector_bonus(t_pipex_bonus *pipex, char **argv,
			char **envp, int i)
{
	if (i == 0)
		first_child_bonus(pipex, argv, envp);
	else if (i + 1 == pipex->cmd)
		last_child_bonus(pipex, argv, envp);
	else
		middle_child_bonus(pipex, argv, envp, i);
}
