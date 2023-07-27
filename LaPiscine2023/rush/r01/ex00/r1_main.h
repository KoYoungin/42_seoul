/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r1_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:08:55 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 21:45:14 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R1_MAIN_H
# include "libft/libft.h"

# define R1_MAIN_H
# define R1_TRUE    1
# define R1_FALSE   0

void	set_rowline(int row_col[2], int map[4][4], int height, int *rowline);
void	set_colline(int row_col[2], int map[4][4], int height, int *colline);
int		*set_row_col(int r, int c);
void	set_free(int *n);
int		solve(int row_col[2], int views[16], int map[4][4]);

#endif
