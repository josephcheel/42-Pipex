/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:00:56 by jcheel-n          #+#    #+#             */
/*   Updated: 2022/08/04 13:22:08 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	char	find;

	find = (char)c;
	len = ft_strlen(s);
	str = (char *)s;
	if (!s)
		return (NULL);
	while (len + 1 > 0)
	{
		if (*str == find)
			return (str);
		str++;
		len--;
	}	
	return (NULL);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_strlcpy(str + s1len, s2, s2len + 1);
	return (str);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	size_t			needlelen;

	needlelen = ft_strlen(needle);
	i = 0;
	if (!needle)
		return ((char *)haystack);
	while (*haystack && len > needlelen
		&& ft_strncmp(haystack, needle, needlelen))
	{
		haystack++;
		len--;
	}
	if (len >= needlelen && !ft_strncmp(haystack, needle, needlelen))
		return ((char *)haystack);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}
