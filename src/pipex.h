/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 05:49:05 by aylamgha          #+#    #+#             */
/*   Updated: 2024/03/11 10:15:15 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

int		open_file(char *file, int n);
int		accessing(char *file, int in_or_out);
char	*my_env(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	exec(char *cmd, char **env);
void	my_child(char **av, int *p_fd, char **env);
void	my_parent(char **av, int *p_fd, char **env);
void	freeing(char **tab);
void	exiting(int n_exit);
void	ft_helper(char **av, char **env, int *p_fd, pid_t pid2);
void	ft_helper2(char **av, char **env, int *p_fd);
#endif
