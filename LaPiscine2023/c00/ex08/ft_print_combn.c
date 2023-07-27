/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:21:56 by younko            #+#    #+#             */
/*   Updated: 2023/02/20 17:47:45 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(char num[], int n)
{	
	int	i;
	int	k;

	k = 1;
	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i], 1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if ((num[i] - '0') + n - i != 10)
			k = 0;
		i++;
	}
	if (k != 1)
		write(1, ", ", 2);
}

void	ft_cal_comb(int r, int d, int i, char list[])
{
	if (d == r)
		ft_putnum(list, r);
	else if (i < 10 && d < r)
	{
		list[d] = '0' + i;
		ft_cal_comb(r, d + 1, i + 1, list);
		ft_cal_comb(r, d, i + 1, list);
	}
}

void	ft_print_combn(int n)
{
	char	list[10];

	list[n] = '\0';
	ft_cal_comb(n, 0, 0, list);
}
