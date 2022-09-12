/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:50:36 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/06/30 12:32:41 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	commandline(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (!str1[i])
		return (1);
	else
		return (0);
}

char	*commandroute(char **env, char *command)
{
	char	**route;
	char	*line;
	char	**temp;
	int		i;

	if (ft_strnstr(command, ".sh", ft_strlen(command))
		&& !ft_strchr(command, '/'))
		return (NULL);
	if (ft_strnstr(command, ".sh", ft_strlen(command)))
		return (command);
	while (!commandline("PATH", *env))
		env++;
	line = *env;
	while (*line != '/')
		line++;
	route = ft_split(line, ':');
	temp = ft_split(command, ' ');
	route = command_add(route, temp[0]);
	i = 0;
	while (route[i] && access(route[i], F_OK) == -1)
		i++;
	if (!route[i])
		return (command);
	return (route[i]);
}

char	**command_arg(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	return (args);
}

char	**command_add(char **route, char *command)
{
	char	*copy;
	int		i;

	i = 0;
	copy = ft_strdup("/");
	if (!copy)
		function_errors();
	copy = ft_strjoinfree(copy, command);
	if (!copy)
		function_errors();
	while (route[i])
	{
		route[i] = ft_strjoinfree(route[i], copy);
		if (!route[i])
			function_errors();
		i++;
	}
	route[i] = NULL;
	free(copy);
	return (route);
}

char	*command_arguments(char *av)
{
	char	**args;

	args = ft_split(av, ' ');
	if (!args)
		function_errors();
	return (args[0]);
}

// int main(int ac, char **av, char **env)
// {
// 	printf("%s", commandroute(env, "wc"));

// }