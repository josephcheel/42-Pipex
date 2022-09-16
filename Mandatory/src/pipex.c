/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:14 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/06/30 13:16:10 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

void	second_child(t_pipex pipex, char **av, char **env)
{
	close(pipex.fd[1]);
	pipex.outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (pipex.outfile == -1)
		function_errors();
	if (outfile_errors(av) == -1)
		function_errors();
	if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
		function_errors();
	close(pipex.fd[0]);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		function_errors();
	execute_command(av[3], env);
}

void	first_child(t_pipex pipex, char **av, char **env)
{
	if (infile_errors(av) == -1)
		return ;
	close (pipex.fd[0]);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
		function_errors();
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		function_errors();
	close(pipex.infile);
	if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
		function_errors();
	close(pipex.fd[1]);
	execute_command(av[2], env);
}

void	ft_program(char **av, char **env)
{
	t_pipex	pipex;

	if (pipe(pipex.fd) == -1)
		function_errors();
	pipex.pid = fork();
	if (pipex.pid == -1)
		function_errors();
	else if (pipex.pid == 0)
		first_child(pipex, av, env);
	else if (pipex.pid > 0)
	{
		pipex.pid = fork();
		if (pipex.pid == -1)
			function_errors();
		else if (pipex.pid == 0)
			second_child(pipex, av, env);
		else if (pipex.pid > 0)
		{
			close(pipex.fd[0]);
			close(pipex.fd[1]);
		}
	}
	waitpid(pipex.pid, NULL, 0);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	if (ac == 5)
		ft_program(av, env);
	write(2, "usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 45);
	exit(EXIT_FAILURE);
}
