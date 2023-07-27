/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:14 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 03:50:57 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

int	check_right_map(char *line, t_rule *rule)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
		if (line[i] != rule->empt && line[i] != rule->obst)
			return (0);
	return (1);
}

void	free_ml(char **map, char *line, int r)
{
	int	i;

	i = -1;
	while (++i < r)
		free(map[i]);
	free(map);
	free(line);
}

int	ft_alloc_map(char *line, char **map, t_rule *rule, int r)
{
	int	s_len;
	int	check;

	check = 1;
	s_len = ft_strlen(line);
	if (rule->col != 0 && rule->col != s_len)
		check = 0;
	else if (rule->col == 0)
		rule->col = s_len;
	if (check_right_map(line, rule) == 0)
	{
		free_ml(map, line, r);
		check = 0;
	}
	else
	{
		map[r] = ft_strdup(line);
		if (map[r] == NULL)
			check = 0;
	}
	return (check);
}
