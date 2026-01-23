/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:50:14 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/09 16:56:46 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substring(char *a, unsigned int index, size_t size)
{
	size_t	len;
	char	*subs;
	size_t	i;
	size_t	sizee;

	if (!a)
		return (NULL);
	i = 0;
	len = ft_strlen(a);
	if (index > len)
		return (ft_strdup(""));
	sizee = len - index;
	if (size > sizee)
		size = sizee;
	subs = malloc((size + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (a[index] && i < size)
	{
		subs[i] = a[i + index];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			a;

	if (!s)
		return (NULL);
	a = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *)&s[i]);
	return (NULL);
}
