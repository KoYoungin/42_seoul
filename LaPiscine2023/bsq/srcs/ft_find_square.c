/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:48:56 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 02:36:21 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

int		ft_find_square(t_rule *rule, char **map, t_sol *sol);
void	ft_square(t_rule *rule, char **map, int pos[2], t_sol *sol);
int		calc_square_size(t_rule *rule, char **map, int pos[2], int sq_size);

int	ft_find_square(t_rule *rule, char **map, t_sol *sol)
{
	int	y;
	int	x;
	int	pos[2];

	y = 0;
	while (y < rule->row)
	{
		x = 0;
		while (x < rule->col)
		{
			if (map[y][x] == rule->empt)
			{
				pos[0] = y;
				pos[1] = x;
				ft_square(rule, map, pos, sol);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_square(t_rule *rule, char **map, int pos[2], t_sol *sol)
{
	int	tmp_size;
	int	square_size;
	int	y;
	int	x;

	y = pos[0];
	x = pos[1];
	if (rule->col - x > rule->row - y)
		square_size = rule->row - y;
	else
		square_size = rule->col - x;
	tmp_size = calc_square_size(rule, map, pos, square_size);
	if (sol->n < tmp_size)
	{
		sol->n = tmp_size;
		sol->y_c = y;
		sol->x_r = x;
	}		
}

int	calc_square_size(t_rule *rule, char **map, int pos[2], int square_size)
{
	int	y;
	int	x;
	int	cur_y;
	int	cur_x;

	cur_y = pos[0];
	cur_x = pos[1];
	y = cur_y - 1;
	while (++y < (cur_y + square_size))
	{
		x = cur_x - 1;
		while (++x < (cur_x + square_size))
		{
			if (map[y][x] == rule->obst)
			{
				pos[0] = cur_y;
				pos[1] = cur_x;
				return (calc_square_size(rule, map, pos, square_size - 1));
			}
		}
	}
	return (square_size);
}
