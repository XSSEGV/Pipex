/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 05:48:23 by aylamgha          #+#    #+#             */
/*   Updated: 2024/03/14 06:26:00 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*my_env(char *name, char **env)
{
	int		x;
	int		y;
	char	*sub;

	x = 0;
	while (env[x])
	{
		y = 0;
		while (env[x][y] && env[x][y] != '=')
			y++;
		sub = ft_substr(env[x], 0, y);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[x] + y + 1);
		}
		free(sub);
		x++;
	}
	return (NULL);
}

void	freeing2(char **s, char **t)
{
	freeing(s);
	freeing(t);
}

char	*get_path(char *cmd, char **env)
{
	int		x;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	x = -1;
	allpath = ft_split(my_env("PATH", env), ':');
	if (allpath == NULL || *allpath == NULL)
		return (cmd);
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++x])
	{
		path_part = ft_strjoin(allpath[x], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			freeing2(s_cmd, allpath);
			return (exec);
		}
		free(exec);
	}
	freeing2(s_cmd, allpath);
	return (cmd);
}
