/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:59:13 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/22 19:40:07 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define OK_END 0
# define CMD_NOT_FOUND -1
# define NO_FILE -2
# define NO_PERM -3
# define INV_ARGS -4
# define NO_MEMORY -5
# define PIPE_ERR -6
# define DUP_ERR -7
# define FORK_ERR -8
# define NO_PATH -9
# define CMD_FAIL -10
# define ERR_MALLOC -11
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

typedef struct s_pipex
{
	int		input_fd;
	int		output_fd;
	int		fd_pipe[2];
	char	**paths;
	char	**argv_cmd;
	char	*cmd_path;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

//pipex_child.c
void	first_child(t_pipex *pipex, char **argv, char **envp);
void	second_child(t_pipex *pipex, char **argv, char **envp);

//pipex_error.c
void	pipex_print_msg(char *param, int error);
void	pipex_error_exit(char *param, int error);
void	malloc_error_exit(void);
void	px_error_free(t_pipex *pipex, char *param, int err);

//pipex_path.c
char	**split_path(char **envp);
char	*get_cmd_path(char	*cmd, char **paths_array);

//pipex_free.c
void	free_aray(char **aray);
void	free_child(t_pipex *pipex);
void	free_parent_closefd(t_pipex *pipex);

#endif