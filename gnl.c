#include "gnl.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int		i = 0;
	char	buff[0];
	char	tmp[8000000];
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp[0] = '\0';
	while (read(fd, buff, BUFFER_SIZE) == 1)
	{
		tmp[i] = buff[0];
		tmp[i + 1] = '\0';
		if (tmp[i++] == '\n')
			break ;
	}
	if (tmp[0] == '\0')
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (tmp[++i])
		line[i] = tmp[i];
	line[i] = '\0';
	return (line);
}
