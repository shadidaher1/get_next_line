#include "get_next_line.h"
char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	var = ft_strdup("");
	line = fill_line(fd, buffer, var);
	free(buffer);
	buffer = NULL;
	if (!line)
		free(line);
	
}

static char *fill_line(int fd, char *buffer, char *var)
{
	ssize_t res;
	char *tmp;

	res = 1;
	while (res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[res] = '\0';
		tmp = var;
		var = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			return (var);
	}
	return (var);
}
static char *ft_strchr(char *s, int c)
{
	unsigned int i;
	char a;

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