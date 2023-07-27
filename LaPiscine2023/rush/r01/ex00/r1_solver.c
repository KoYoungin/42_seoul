/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r1_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:46:47 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 21:26:19 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r1_main.h"
#include "r1_err.h"

int	verify_view_leftup(int line[4], int view)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
		i++;
	}
	return (count == view);
}

int	verify_view_rightdown(int line[4], int view)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 3;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			count++;
			max = line[i];
		}
		i--;
	}
	return (count == view);
}

int	verify_map(int row_col[2], int views[16], int map[4][4], int height)
{
	int	i;
	int	rowline[4];
	int	colline[4];

	i = -1;
	while (++i < 4)
		if (map[row_col[0]][i] == height || map[i][row_col[1]] == height)
			return (R1_FALSE);
	if (row_col[1] == 3)
	{
		set_rowline(row_col, map, height, rowline);
		if (verify_view_leftup(rowline, views[row_col[0] + 8]) == R1_FALSE)
			return (R1_FALSE);
		if (verify_view_rightdown(rowline, views[row_col[0] + 12]) == R1_FALSE)
			return (R1_FALSE);
	}
	if (row_col[0] == 3)
	{
		set_colline(row_col, map, height, colline);
		if (verify_view_leftup(colline, views[row_col[1]]) == R1_FALSE)
			return (R1_FALSE);
		if (verify_view_rightdown(colline, views[row_col[1] + 4]) == R1_FALSE)
			return (R1_FALSE);
	}
	return (R1_TRUE);
}

int	solve(int row_col[2], int views[16], int map[4][4])
{
	int	height;
	int	*nxt_r_c;

	if (row_col[0] == 4)
		return (R1_OK);
	nxt_r_c = set_row_col(row_col[0], row_col[1] + 1);
	if (nxt_r_c[1] == 4)
		nxt_r_c = set_row_col(nxt_r_c[0] + 1, 0);
	if (map[row_col[0]][row_col[1]])
		return (solve(nxt_r_c, views, map));
	height = 0;
	while (++height <= 4)
	{
		if (verify_map(row_col, views, map, height))
		{
			map[row_col[0]][row_col[1]] = height;
			if (solve(nxt_r_c, views, map) == R1_OK)
				return (R1_OK);
			map[row_col[0]][row_col[1]] = 0;
		}
	}
	set_free(nxt_r_c);
	return (R1_ERR);
}
