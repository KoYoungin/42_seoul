/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:24:32 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 04:10:55 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_map(char **map, t_rule *rule, t_sol *sol)
{
	int	y;
	int	x;

	y = -1;
	while (++y < rule->row)
	{
		x = -1;
		while (++x < rule->col)
		{
			if (x >= sol->x_r && x <= sol->x_r + sol->n - 1 \
					&& y >= sol->y_c && y <= sol->y_c + sol->n - 1)
				ft_putchar(rule->full);
			else
				ft_putchar(map[y][x]);
		}
		ft_putchar('\n');
	}
	ft_free_map(map, rule, sol);
	if (rule != NULL)
		free(rule);
}

t_all	*make_all(t_all *all, char *file)
{
	all->rule = make_rule();
	all->sol = make_sol();
	if (all->rule == NULL || all->sol == NULL)
	{
		free(all);
		return (NULL);
	}
	all->map = ft_parse_map(all->rule, all->map, file);
	if (all->map == NULL)
	{
		if (all->rule != NULL)
			free(all->rule);
		if (all->sol != NULL)
			free(all->sol);
		if (all != NULL)
			free(all);
		return (NULL);
	}
	return (all);
}

void	solve(t_all *all, char *file)
{
	all = malloc(sizeof(t_all));
	all = make_all(all, file);
	if (all != NULL)
	{
		if (ft_find_square(all->rule, all->map, all->sol) == 0)
			ft_putstr("map error\n");
		else
			print_map(all->map, all->rule, all->sol);
		free(all);
	}
	else
		ft_putstr("map error\n");
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		i;

	all = 0;
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			solve(all, argv[i]);
	}
	else
		solve(all, NULL);
	return (0);
}
