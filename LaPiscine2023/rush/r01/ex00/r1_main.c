/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r1_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:46:38 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 20:11:04 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r1_main.h"
#include "r1_err.h"

void	print_error(void)
{
	write(1, R1_ERRMSG, R1_ERRMSG_LEN);
	return ;
}

int	parse_arg(char *arg, int *views)
{
	char	*ptr;
	int		i;

	ptr = ft_strtok(arg, ' ');
	i = 0;
	while (ptr)
	{
		if (i == 16)
			return (R1_ERR);
		views[i] = ft_atoi(ptr);
		if (views[i] <= 0 || views[i] > 5)
			return (R1_ERR);
		ptr = ft_strtok(NULL, ' ');
		i++;
	}
	if (i == 16)
		return (R1_OK);
	else
		return (R1_ERR);
}

void	print_map(int map[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(map[i][j]);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int	views[16];
	int	map[4][4];
	int	row_col[2];

	if (argc != 2)
	{
		print_error();
		return (R1_ERR);
	}
	if (parse_arg(argv[1], views) != R1_OK)
	{
		print_error();
		return (R1_ERR);
	}
	ft_bzero(map, sizeof(map));
	row_col[0] = 0;
	row_col[1] = 0;
	if (solve(row_col, views, map) != R1_OK)
	{
		print_error();
		return (R1_ERR);
	}
	print_map(map);
	return (R1_OK);
}
