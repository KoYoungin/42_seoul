/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:32:51 by younko            #+#    #+#             */
/*   Updated: 2023/02/13 18:32:53 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(char num[])
{
	write(1, num, 3);
	if (num[0] != '7' || num[1] != '8' || num[2] != '9')
		write(1, ", ", 2);
}

void	ft_cal_comb(int d, int i, char num[], char list[])
{
	if (d == 3)
		ft_putnum(list);
	else if (i < 10 && d < 3)
	{	
		list[d] = num[i];
		ft_cal_comb(d + 1, i + 1, num, list);
		ft_cal_comb(d, i + 1, num, list);
	}
}

void	ft_print_comb(void)
{
	char	num[10];
	char	list[3];
	char	i;

	i = '0';
	while (i <= '9')
	{
		num[i - '0'] = i;
		i++;
	}
	ft_cal_comb(0, 0, num, list);
}
