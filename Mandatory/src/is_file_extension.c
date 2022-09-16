/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:07:10 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/04 14:07:11 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

int	is_file_extension(char *file, char *type)
{
	int	len;
	int	type_len;
	int	max;

	len = ft_strlen(file);
	type_len = ft_strlen(type);
	max = ft_strlen(file) - ft_strlen(type);
	while (max < len)
	{
		if (type_len > 0)
		{
			if (file[len - 1] == type[type_len - 1])
			{
				len--;
				type_len--;
			}
			else
				return (0);
		}
		if (type_len == 0)
			return (1);
	}
	return (0);
}

// int main(void)
// {
// 	char *file = "holsa.ber";
// 	char *extension = ".ber";
// 	printf("%d", is_file_extension(file, extension));

// }
