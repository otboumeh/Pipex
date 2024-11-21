/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:26:41 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 19:56:10 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex_bonus.h"

static void	create_pipes_bonus(t_pipex_bonus *pipex)
{
	int	i;

	pipex->pipe = (int *)malloc((pipex->cmd - 1) * 2 * sizeof(int));
	if (!pipex->pipe)
		malloc_error_exit();
	i = 0;
	while (i < (pipex->cmd - 1))
	{
		if (pipe(pipex->pipe + 2 * i) == -1)
		{
			free(pipex->pipe);
			perror_exit_bonus(PIPE_ERR, NULL);
		}
		i++;
	}
}

static void	open_files_bonus(t_pipex_bonus *pipex, int argc, char **argv)
{
	if (pipex->here_doc)
		pipex->input_fd = open("/tmp/.here_doc", O_RDONLY, 0000644);
	else
		pipex->input_fd = open(argv[1], O_RDONLY);
	if (pipex->here_doc)
		pipex->output_fd = open (argv[5], O_APPEND
				| O_CREAT | O_WRONLY, 0000644);
	else
		pipex->output_fd = open(argv[argc - 1], O_TRUNC
				| O_CREAT | 01, 0000644);
}

static void	init_pipex_bonus(t_pipex_bonus *pipex, int argc,
				char **argv, char **envp)
{
	if (pipex->here_doc)
		pipex->cmd = 2;
	else
		pipex->cmd = argc - 3;
	open_files_bonus(pipex, argc, argv);
	pipex->paths = split_path(envp);
	pipex->pid = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd);
	if (!pipex->pid)
		malloc_error_exit();
	create_pipes_bonus(pipex);
}

static bool	child_from_parent(t_pipex_bonus pipex, int child_index)
{
	int	i;

	i = 0;
	while (i < child_index)
	{
		if (pipex.pid[i] == 0)
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_bonus	pipex;
	int				i;
	if (argc < 5)
		return (0);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) && argc == 6)
		here_doc(&pipex, argv);
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) && argc >= 5)
		pipex.here_doc = false;
	else
		perror_exit_bonus(INV_ARGS, NULL);
	init_pipex_bonus(&pipex, argc, argv, envp);
	i = 0;
	while (i < pipex.cmd)
	{
		pipex.pid[i] = fork();
		if (pipex.pid[i] == -1)
		{
			free_parent_bonus(&pipex);
			pipex_error_exit(NULL, FORK_ERR);
		}
		else if (pipex.pid[i] == 0 && child_from_parent(pipex, i))
			child_selector_bonus(&pipex, argv, envp, i);
		i++;
	}
	free_parent_closefd_bonus(&pipex);
	return (0);
}
