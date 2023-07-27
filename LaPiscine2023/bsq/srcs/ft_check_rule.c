/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rule.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:49:25 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 03:43:33 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

int	is_numeric(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len - 3)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] < 32 || str[i] > 126)
			return (0);
	return (1);
}

int	ft_check_rule(t_rule *rule, char *line)
{
	int	check;
	int	line_len;

	check = 1;
	if (rule->row <= 0 || is_printable(line) == 0)
		check = 0;
	line_len = ft_strlen(line);
	if (line_len < 4 || is_numeric(line, line_len) == 0)
		check = 0;
	rule->empt = line[line_len - 3];
	rule->obst = line[line_len - 2];
	rule->full = line[line_len - 1];
	free(line);
	if (rule->empt == rule->obst)
		check = 0;
	if (rule->empt == rule->full)
		check = 0;
	if (rule->obst == rule->full)
		check = 0;
	return (check);
}
