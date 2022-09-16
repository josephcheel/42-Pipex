/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_script.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:27:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/03 12:27:03 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

char	**ft_split_script(char *str)
{
	char	**split;

	split = malloc(sizeof(char) * 2);
	if (!split)
		return (NULL);
	split[0] = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!split[0])
		return (NULL);
	ft_strlcpy(split[0], str, ft_strlen(str));
	split[1] = NULL;
	return (split);
}
