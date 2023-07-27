/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r1_setline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:54:41 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 21:26:54 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	set_rowline(int row_col[2], int map[4][4], int height, int *rowline)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		rowline[i] = map[row_col[0]][i];
		i++;
	}
	rowline[row_col[1]] = height;
	return ;
}

void	set_colline(int row_col[2], int map[4][4], int height, int *colline)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		colline[i] = map[i][row_col[1]];
		i++;
	}
	colline[row_col[0]] = height;
	return ;
}

int	*set_row_col(int r, int c)
{
	int	*row_col;

	row_col = (int *)malloc(sizeof(int) * 2);
	row_col[0] = r;
	row_col[1] = c;
	return (row_col);
}

void	set_free(int *n)
{
	free(n);
}
