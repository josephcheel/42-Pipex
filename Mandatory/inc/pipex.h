/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:06:57 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/04 15:31:06 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid;
	int		outfile;
	int		infile;
}t_pipex;

int		infile_errors(char **av);
int		outfile_errors(char **av);
void	function_errors(void);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_substrfree(char const *s, unsigned int start,
			size_t len, int freeme);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_free(char **ret, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//char	*ft_splitquote(char *str);
//int		quote_arg_lenght(char *str);
//char	*param_checker(char *param);

char	*findroute(char **av, char *command);
int		commandline(char *str1, char *str2);
char	*commandroute(char **env, char *command);
char	**command_arg(char *av);
char	**command_add(char **route, char *command);
char	**ft_split_quotes(char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_script(char *str);
char	**ft_split_script(char *str);
char	*command_arguments(char *av);
int		ft_get_words(char *str);
char	*ft_strchr(const char *s, int c);
void	exec_error(char *command);
void	execute_command(char *av, char **env);

char	**ft_ignore_backslash(char **split);

int		is_file_extension(char *file, char *type);
#endif 
