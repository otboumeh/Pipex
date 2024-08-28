/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:04 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 18:38:37 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "./pipex.h"
# include "../libft/libft.h"
# define ERR_HEREDOC -12
# define ERR_RDHEREDOC -13
# define ERR_HEREDOC_EOF -14

typedef struct s_pipex_bonus
{
	int		input_fd;
	int		output_fd;
	int		*pipe;
	int		cmd;
	bool	here_doc;
	char	**paths;
	char	**argv_cmd;
	char	*cmd_path;
	pid_t	*pid;
}	t_pipex_bonus;

//pipex_childs_bonus.c
void	first_child_bonus(t_pipex_bonus *pipex, char **argv, char **envp);
void	last_child_bonus(t_pipex_bonus *pipex, char **argv, char **envp);
void	child_selector_bonus(t_pipex_bonus *pipex, char **argv,
			char **envp, int i);
void	middle_child_bonus(t_pipex_bonus *pipex, char **argv, char **envp, int i);


//pipex_check_files.c
void	pxb_check_infile(t_pipex_bonus *pipex, char **argv);
void	pxb_check_outfile(t_pipex_bonus *pipex, char **argv);

//pipex_error_msg_bonus.c
void	error_msg_bonus(int err, char *param);
void	perror_exit_bonus(int err, char *param);
void	cmd_not_found_bonus(t_pipex_bonus *pipex);
void	cmd_fail_exit_bonus(t_pipex_bonus *pipex);

//pipex_free_close_bonus.c
void	pxb_close_pipes(t_pipex_bonus *pipex);
void	free_parent_bonus(t_pipex_bonus *pipex);
void	free_parent_closefd_bonus(t_pipex_bonus *pipex);

//pipex_here_doc.c
void	here_doc(t_pipex_bonus *pipex, char **argv);


#endif