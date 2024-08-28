/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:04 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/28 11:50:35 by otboumeh         ###   ########.fr       */
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


#endif