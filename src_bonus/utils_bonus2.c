/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:00:14 by aylamgha          #+#    #+#             */
/*   Updated: 2024/03/11 10:15:40 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exiting(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(127);
}

int	accessing(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	return (open(file, O_RDONLY, 0777));
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = accessing(file);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
		exit(1);
	return (ret);
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

int	ft_helper3(char **av, int ac, int *fd_in, int *fd_out)
{
	*fd_in = open_file(av[1], 0);
	*fd_out = open_file(av[ac - 1], 1);
	dup2(*fd_in, 0);
	return (2);
}
