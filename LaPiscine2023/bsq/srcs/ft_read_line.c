/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:50:25 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 03:44:35 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

char	*plus_line(char *line, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] != '\0')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (new == NULL)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (line[++i] != '\0')
		new[i] = line[i];
	new[i++] = buf[0];
	new[i] = '\0';
	free(line);
	return (new);
}

int	alloc_rule(char *line, t_rule *rule)
{
	char	*dup_num;

	dup_num = ft_strndup(line, ft_strlen(line) - 3);
	rule->row = ft_atoi(dup_num);
	free(dup_num);
	if (ft_check_rule(rule, line) == 0)
		return (0);
	return (1);
}

char	*ft_read_rule(char *map_path, t_rule *rule, int *f)
{
	char	*all;
	int		fd;
	char	buf[1];

	all = malloc(sizeof(char));
	all[0] = '\0';
	if (map_path == NULL)
		fd = 0;
	else
		fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, buf, 1) != 0 && buf[0] != '\n')
	{
		all = plus_line(all, buf);
		if (all == NULL)
			return (NULL);
	}
	if (ft_strlen(all) < 4 || alloc_rule(all, rule) == 0)
	{
		free(all);
		return (NULL);
	}
	*f = fd;
	return (all);
}
