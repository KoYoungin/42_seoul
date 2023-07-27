/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:52:21 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 15:48:21 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_cal_base(char *str)
{
	int	base;
	int	i;
	int	j;

	if (*str == '\0' || *(str + 1) == '\0')
		return (0);
	i = 0;
	j = 0;
	base = 0;
	while (str[i] != '\0')
	{
		j = i +1;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		base++;
		i++;
	}
	return (base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n_base;

	n_base = ft_cal_base(base);
	if (n_base)
	{
		if (nbr == -2147483648)
		{
			write(1, "-", 1);
			ft_putnbr_base((nbr / n_base) * (-1), base);
			ft_putnbr_base((nbr % n_base) * (-1), base);
			return ;
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr < n_base)
			write(1, &base[nbr], 1);
		else
		{
			ft_putnbr_base(nbr / n_base, base);
			ft_putnbr_base(nbr % n_base, base);
		}
	}
}
