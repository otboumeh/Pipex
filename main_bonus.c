/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:41 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/27 17:38:54 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex_bonus.h"

static void	open_files_bonus(t_pipex_bonus *pipex, int argc, char **argv)
{
	pipex->input_fd = open(argv[1], O_RDONLY);
	pipex->output_fd = open(argv[argc - 1], O_TRUNC | O_CREAT | 01,0000644);
}

static void	init_pipex_bonus(t_pipex_bonus *pipex, int argc,
				 char **argv, char **envp)
{
	pipex->cmd = argc - 3;
	open_files_bonus(pipex, argc, argv);
	pipex->paths = split_path(envp);
	pipex->pid = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd);
	if (!pipex->pid)
		malloc_error_exit();
	
}

int main(int argc, char **argv, char **envp)
{
	t_pipex_bonus pipex;
	int i;

	init_pipex_bonus(&pipex, argc, argv, envp);	
	i = 0;
	
}