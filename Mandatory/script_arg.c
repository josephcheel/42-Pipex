/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:26:31 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/03 12:26:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static void	ft_copy(char *new, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == 34 || str[i] == 39) && str[i - 1] != 92)
			i++;
		else
		{
			if (str[i] == 92)
				i++;
			else
			{
				new[j] = str[i];
				i++;
				j++;
			}
		}
	}
	new[j] = '\0';
}

char	*ft_cleaner(char *str)
{
	int		i;
	int		j;
	size_t	len;
	char	*new;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if ((str[i] == 34 || str[i] == 39) && str[i - 1] != 92)
			j++;
		i++;
	}
	new = malloc(sizeof(char) * len - j + 1);
	if (!new)
		return (NULL);
	ft_copy(new, str);
	return (new);
}

char	*ft_script(char *str)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	return (ft_cleaner(str));
}
