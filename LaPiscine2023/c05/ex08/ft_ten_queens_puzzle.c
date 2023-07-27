/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:35:05 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 21:25:33 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_impo_index(int cur_q, int cur_i, char *chess)
{
	int	i;
	int	d_x;
	int	d_y;

	i = -1;
	while (++i < cur_q)
	{
		d_x = ft_abs(chess[i] - '0' - cur_i);
		d_y = ft_abs(i - cur_q);
		if (chess[i] - '0' == cur_i || d_x == d_y)
			return (0);
	}
	return (1);
}

void	ft_cal_queen(int cur_q, char *chess, int *rst)
{
	int		i;

	if (cur_q == 10)
	{
		*rst += 1;
		i = -1;
		while (++i < 10)
		{
			write(1, &chess[i], 1);
		}
		write(1, "\n", 1);
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (ft_impo_index(cur_q, i, chess) == 1)
			{
				chess[cur_q] = i + '0';
				ft_cal_queen(cur_q + 1, chess, rst);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	index[10];
	int		rst;

	rst = 0;
	ft_cal_queen(0, index, &rst);
	return (rst);
}
