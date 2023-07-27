/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:04:11 by younko            #+#    #+#             */
/*   Updated: 2023/02/13 17:44:39 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(char num[])
{
	write(1, &num[0], 1);
	write(1, &num[1], 1);
	write(1, " ", 1);
	write(1, &num[2], 1);
	write(1, &num[3], 1);
	if (num[0] != '9' || num[1] != '8' || num[2] != '9' || num[3] != '9')
		write(1, ", ", 2);
}

void	ft_cal_comb(int d, int i, char num[][2], char list[])
{
	if (d == 4)
		ft_putnum(list);
	else if (i < 100 && d < 4)
	{
		list[d] = num[i][0];
		list[d + 1] = num[i][1];
		ft_cal_comb(d + 2, i + 1, num, list);
		ft_cal_comb(d, i + 1, num, list);
	}
}

void	ft_print_comb2(void)
{
	char	num[100][2];
	char	list[4];
	char	i;
	char	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			num[10 * (i - '0') + (j - '0')][0] = i;
			num[10 * (i - '0') + (j - '0')][1] = j;
			j++;
		}
		i++;
	}
	ft_cal_comb(0, 0, num, list);
}
