/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:29:22 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 16:43:18 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"


static void	here_doc_read(t_pipex_bonus *pipex, char *limiter)
{
	char	*line;

	while (1)
	{
		write (1, "> ", 2);
		line = get_next_line(0);
		if (!line)
		{
			ft_putchar_fd('\n', 2);
			perror_exit_bonus(ERR_HEREDOC_EOF, limiter);
		}
		if (!ft_strncmp(line, limiter, ft_strlen(line) - 1))
		{
			free(line);
			return ;
		}
		write(pipex->input_fd, line, ft_strlen(line));
		free(line);
	}
}


void	here_doc(t_pipex_bonus *pipex, char **argv)
{
	char	*limiter;

	pipex->input_fd = open("/tmp/.here_doc", O_CREAT | 01 | O_TRUNC, 0000644);
	if (pipex->input_fd < 0)
		perror_exit_bonus(ERR_HEREDOC, NULL);
	pipex->here_doc = true;
	limiter = argv[2];
	here_doc_read(pipex, limiter);
	close(pipex->input_fd);
}