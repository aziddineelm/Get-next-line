/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:27:09 by ael-mans          #+#    #+#             */
/*   Updated: 2025/01/04 14:18:29 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), NULL);
	i = 1;
	while (i && !ft_contain(buffer, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest_buff(char *buffer)
{
	char	*rest_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	rest_buffer = malloc(ft_strlen(buffer) - i + 1);
	if (!rest_buffer)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		rest_buffer[j++] = buffer[i++];
	rest_buffer[j] = '\0';
	free(buffer);
	return (rest_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer[fd] = ft_read(buffer[fd], fd);
	if (!buffer[fd])
		return (buffer[fd]);
	if (!buffer[fd][0])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_rest_buff(buffer[fd]);
	return (line);
}
