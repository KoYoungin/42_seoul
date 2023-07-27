/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:54 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 04:08:55 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

char	**save_map(int fd, char **map, t_rule *rule, int r_cnt)
{
	char	*line;
	char	buf[1];

	line = new_line(NULL);
	while (read(fd, buf, 1) != 0 && r_cnt < rule->row)
	{
		if (buf[0] != '\n')
		{
			line = plus_line(line, buf);
			if (line == NULL)
				return (NULL);
		}
		else
		{
			if (ft_alloc_map(line, map, rule, r_cnt++) == 0)
				return (NULL);
			line = new_line(line);
		}
		if (buf[0] == '\n' && r_cnt == rule->row)
			break ;
	}
	free(line);
	if (fd != 0 && (read(fd, buf, 1) != 0 || r_cnt < rule->row))
		return (NULL);
	return (map);
}

char	**ft_parse_map(t_rule *rule, char **map, char *map_path)
{
	char	*all;
	int		fd;
	int		r_cnt;

	all = ft_read_rule(map_path, rule, &fd);
	if (all == NULL)
	{	
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (rule->row + 1));
	if (map == NULL)
		return (NULL);
	map[rule->row] = 0;
	r_cnt = 0;
	map = save_map(fd, map, rule, r_cnt);
	if (map == NULL)
		return (NULL);
	close(fd);
	return (map);
}
