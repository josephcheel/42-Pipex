/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/06/30 12:32:35 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

int	infile_errors(char **av)
{
	if (access(av[1], F_OK) == -1)
	{
		write(2, "pipex: ", 7);
		write(2, av[1], ft_strlen(av[1]));
		write(2, ": No such file or directory", 27);
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) == -1)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	outfile_errors(char **av)
{
	if (access(av[4], W_OK) == -1)
	{
		perror(av[4]);
		return (-1);
	}
	return (0);
}

void	function_errors(void)
{
	strerror(errno);
	exit(EXIT_FAILURE);
}
/*perror(strerror(errno));
ft_printff("%s", s)trerror(errno);*/

void	exec_error(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": command not found", 19);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
