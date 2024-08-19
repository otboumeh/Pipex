/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:16:53 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/19 13:23:49 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	if (argc != 5)
		pipex_error_exit(NULL, INV_ARGS);
	pipex.input_fd = open(argv[1],O_RDONLY);
	pipex.output_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	pipex.paths = split_path(envp);
		if (pipe(pipex.fd_pipe) < 0)
			pipex_error_exit(NULL, PIPE_ERR);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		pipex_error_exit(NULL, FORK_ERR);
	if (pipex.pid1 == 0)
		first_child(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		pipex_error_exit(NULL, FORK_ERR);
	
		
}
