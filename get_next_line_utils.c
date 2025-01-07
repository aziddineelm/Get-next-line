/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:44:21 by ael-mans          #+#    #+#             */
/*   Updated: 2025/01/01 17:47:47 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*str_dup;

	len = 0;
	while (s[len])
		len++;
	str_dup = (char *)malloc(len + 1);
	if (!str_dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concstr;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	concstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concstr[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		concstr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	concstr[i] = '\0';
	return (free(s1), concstr);
}

int	ft_contain(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
