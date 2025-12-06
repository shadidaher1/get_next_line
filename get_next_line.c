/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:15:44 by sdaher            #+#    #+#             */
/*   Updated: 2025/12/06 14:07:14 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_first_line(char *data);
static char	*get_static( char *data);
static char	*fill_line(int fd, char *buffer, char *var);

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*data;
	static char	*var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	data = fill_line(fd, buffer, var);
	free(buffer);
	buffer = NULL;
	if (!data)
		return (NULL);
	line = extract_first_line(data);
	var = get_static(data);
	free (data);
	return (line);
}

static char	*get_static( char *data)
{
	size_t	i;
	size_t	j;
	char	*var;

	if (ft_strchr(data, '\n'))
	{
		i = ft_strlen(data);
		j = 0;
		while (data[j])
		{
			if (data[j] == '\n')
				break ;
			j++;
		}
		j += 1;
		var = ft_substring(data, j, i - j);
		return (var);
	}
	return (NULL);
}

static char	*extract_first_line(char *data)
{
	int		i;
	char	*line;

	if (ft_strchr(data, '\n'))
	{
		i = 0;
		while (data[i])
		{
			if (data[i] == '\n')
				break ;
			i++;
		}
		line = ft_substring(data, 0, i + 1);
		return (line);
	}
	line = ft_strdup(data);
	return (line);
}

static char	*fill_line(int fd, char *buffer, char *var)
{
	ssize_t	res;
	char	*tmp;

	res = 1;
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res <= 0)
			break ;
		if (!var)
			var = ft_strdup("");
		buffer[res] = '\0';
		tmp = var;
		var = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(var, '\n'))
			return (var);
	}
	if (!var || var[0] == '\0' || res < 0)
	{
		if (var)
			free(var);
		return (NULL);
	}
	return (var);
}

// int main (void)
// {
// 	char	*line;
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// 	line = get_next_line(fd);
// 	printf("%s",line);
// }