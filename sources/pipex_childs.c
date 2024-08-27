/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:45:10 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/27 14:15:57 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//dup2(pipex->fd_pipe[1], STDOUT_FILENO) :
// Utilisé pour ecrire des données vers un pipe ou un autre processus.
//dup2(pipex->in_fd, STDIN_FILENO) :
//Utilisé pour lire des données depuis un pipe ou un fichier.

#include "../includes/pipex.h"

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	if (pipex->input_fd < 0)
	{
		if (access(argv[1], R_OK) == -1 && !access(argv[1], F_OK))
			pipex_error_exit(argv[1], NO_PERM);
		else
			pipex_error_exit(argv[1], NO_FILE);
		return ;
	}
	if (dup2(pipex->fd_pipe[1], STDOUT_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
	if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	pipex->argv_cmd = ft_split(argv[2], ' ');
	if (!pipex->argv_cmd)
		malloc_error_exit();
	pipex->cmd_path = get_cmd_path(pipex->argv_cmd[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		px_error_free(pipex, pipex->argv_cmd[0], CMD_NOT_FOUND);
		return ;
	}
	if (execve(pipex->cmd_path, pipex->argv_cmd, envp) == -1)
		px_error_free(pipex, pipex->argv_cmd[0], CMD_FAIL);
}

void	second_child(t_pipex *pipex, char **argv, char **envp)
{
	if (pipex->output_fd < 0)
	{
		if (access(argv[4], W_OK) == -1 && !access(argv[4], F_OK))
			pipex_error_exit(argv[4], NO_PERM);
		else
			pipex_error_exit(argv[4], NO_MEMORY);
		return ;
	}
	if (dup2(pipex->fd_pipe[0], STDIN_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
	if (dup2(pipex->output_fd, STDOUT_FILENO) == -1)
		pipex_error_exit(NULL, DUP_ERR);
	pipex->argv_cmd = ft_split(argv[3], ' ');
	if (!pipex->argv_cmd)
		malloc_error_exit();
	pipex->cmd_path = get_cmd_path(pipex->argv_cmd[0], pipex->paths);
	if (!pipex->cmd_path)
	{
		px_error_free(pipex, pipex->argv_cmd[0], CMD_NOT_FOUND);
		return ;
	}
	if (execve(pipex->cmd_path, pipex->argv_cmd, envp) == -1)
		px_error_free(pipex, pipex->argv_cmd[0], CMD_FAIL);
}
