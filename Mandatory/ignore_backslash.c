/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:27:15 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/03 12:27:19 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	countnoslash(char *str)
{
	int	y;
	int	len;

	len = 0;
	y = 0;
	while (str[y])
	{
		if (str[y] == '\\')
			y++;
		else
		{
			len++;
			y++;
		}
	}
	return (len);
}

void	ft_copy_nobackslash(char **split, char **str, int x)
{
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (split[x][y])
	{
		if (split[x][y] == 92)
			y++;
		else
		{
			str[x][z] = split[x][y];
			y++;
			z++;
		}
	}
	str[x][z] = '\0';
}

char	**ft_ignore_backslash(char **split)
{
	char	**str;
	int		x;

	x = 0;
	while (split[x])
		x++;
	str = malloc(sizeof(char *) * x + 1);
	str[x] = NULL;
	x = 0;
	while (split[x])
	{
		str[x] = malloc(sizeof(char) * countnoslash(split[x]) + 1);
		ft_copy_nobackslash(split, str, x);
		x++;
	}
	str[x] = NULL;
	return (str);
}

// int main(void)
// {
//     char *split[3] = {
//         "awk", 
//         "{count++} END \\\"{print count}\\\"",
//         };
//     int i = 0;
//     // split = malloc(sizeof(char *) * 3);
//     // split[0] = "awk";
//     // split[1] = "{count++} END \"{print count}\"";
//     // split[2] = NULL;
//     // printf("%s\n", split[1]);
//     // printf("%d\n%lu", countnoslash(split[1]), strlen(split[1]));
//     char **str = ft_ignore_backslash(split);
//     while (i < 3)
//     {
//         printf("%s\n", str[i]);
//         i++;
//     }
//     // if (strnstr(split, "\\\"", strlne(spli)));
// }
