/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:15:22 by aylamgha          #+#    #+#             */
/*   Updated: 2024/03/11 10:15:23 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exiting(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(0);
}

void	freeing(char **tab)
{
	size_t	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	ft_helper(char **av, char **env, int *p_fd, pid_t pid2)
{
	if (!pid2)
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
		my_parent(av, p_fd, env);
	}
	else
	{
		close(p_fd[0]);
		close(p_fd[1]);
	}
}

void	ft_helper2(char **av, char **env, int *p_fd)
{
	close(p_fd[0]);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[1]);
	my_child(av, p_fd, env);
}

int	accessing(char *file, int in_or_out)
{
	if (access(file, F_OK | R_OK) == -1 && in_or_out == 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	else if (access(file, F_OK) == -1 && in_or_out == 1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		return (-1);
	}
	return (open(file, O_RDONLY, 0777));
}
