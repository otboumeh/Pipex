/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:16:53 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/16 18:02:15 by otboumeh         ###   ########.fr       */
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
		
}
