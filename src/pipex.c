/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 05:49:14 by aylamgha          #+#    #+#             */
/*   Updated: 2024/03/14 05:59:50 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (s_cmd == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		exit(127);
	}
	path = get_path(s_cmd[0], env);
	if (access(path, F_OK | X_OK) == -1)
	{
		ft_putstr_fd("pipex: command not found or not executable: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		freeing(s_cmd);
		exit(127);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		freeing(s_cmd);
		exit(127);
	}
}

void	my_child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	my_parent(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	close(p_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
		exiting(1);
	if (pipe(p_fd) == -1)
		exit(-1);
	pid1 = fork();
	if (pid1 == -1)
		exit(127);
	if (!pid1)
		ft_helper2(av, env, p_fd);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			exit(-1);
		ft_helper(av, env, p_fd, pid2);
		wait(&status);
		wait(&status);
	}
	return (0);
}
