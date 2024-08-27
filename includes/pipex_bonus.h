/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:16:04 by otboumeh          #+#    #+#             */
/*   Updated: 2024/08/27 16:16:58 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H
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
#endif