/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:59:13 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/16 18:03:39 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
#define OK_END 0
#define CMD_NOT_FOUND -1
#define NO_FILE -2
#define NO_PERM -3
#define INV_ARGS -4
#define NO_MEMORY -5
#define PIPE_ERR -6
#define DUP_ERR -7
#define FORK_ERR -8
#define NO_PATH -9
#define CMD_FAIL -10
#define ERR_MALLOC -11

typedef struct s_pipex
{
	int		input_fd;
	int		output_fd;
	int		fd_pipe[2];
	char	**paths;
}	t_pipex;


char **split_path(char **envp);
void	pipex_error_exit(char *param, int error);
void	pipex_print_msg(char *param, int error);

# endif