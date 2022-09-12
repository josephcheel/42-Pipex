/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:31:42 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/03 12:31:45 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	execute_command(char *command, char **env)
{
	char	**str;
	char	**temp;
	char	*route;

	if (ft_strnstr(command, ".sh", ft_strlen(command)))
	{
		if (execve(commandroute(env, ft_script(command)),
				ft_split(command, ' '), env) == -1)
			exec_error(command);
	}
	else
	{
		route = commandroute(env, command);
		temp = ft_split_quotes(command);
		str = ft_ignore_backslash(temp);
		free(temp);
		execve(route, str, env);
		exec_error(command);
	}
}

//PONER COMMANDROUTE(ENV, COMMAND); DENTRO DE EXECVE O FUERA????//
