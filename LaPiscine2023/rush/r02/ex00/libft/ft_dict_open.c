/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:22:55 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:23:22 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*update_line(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != '\0')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		new[i] = str[i];
	new[i++] = buf[0];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*allocate_line(void)
{
	char	*new;

	new = (char *)malloc(sizeof(char));
	new[0] = '\0';
	return (new);
}

int	get_literal(int fd, t_dict **dict)
{
	char	*line;
	char	buffer[1];

	line = allocate_line();
	while (read(fd, buffer, 1) != 0)
	{
		if (buffer[0] != '\n')
		{
			line = update_line(line, buffer);
			if (line == NULL)
				return (0);
		}
		else
		{
			if (alloc_dict(line, dict) == 1)
			{
				free(line);
				line = allocate_line();
			}
			else if (ft_strlen(line) > 1)
				return (0);
		}
	}
	ft_dict_sort(dict);
	return (1);
}

int	ft_dict_open(t_dict **dict, char *dictpath)
{
	int	fd;

	fd = open(dictpath, O_RDWR);
	if (fd == -1)
		return (0);
	if (get_literal(fd, dict) != 0)
		return (1);
	else
		return (0);
	return (0);
}
