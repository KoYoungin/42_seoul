/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:47:36 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 19:47:39 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_len(int nb)
{
	int		res;

	res = 0;
	while (nb != 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

void	ft_put_absnbr(int nb)
{
	char	digit;
	int		len;
	int		oprend;
	int		i;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	len = ft_check_len(nb);
	i = len;
	oprend = 1;
	while (i != 1)
	{
		oprend *= 10;
		i--;
	}
	while (oprend != 0)
	{
		digit = '0' + nb / oprend;
		write(1, &digit, 1);
		nb %= oprend;
		oprend /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
		ft_put_absnbr(nb);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		write(1, "-", 1);
		nb *= -1;
		ft_put_absnbr(nb);
	}
}
