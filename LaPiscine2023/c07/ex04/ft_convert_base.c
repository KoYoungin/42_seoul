/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:22:40 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 22:40:14 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_base(char *base, char c);
int	ft_cal_base(char *str);

int	ft_atoi_base(const char *str, char *base)
{
	int	sign;
	int	rst;
	int	n_base;

	rst = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	n_base = ft_cal_base(base);
	if (n_base == 0)
		return (0);
	while (ft_is_in_base(base, *str) < n_base)
	{
		rst = n_base * rst + ft_is_in_base(base, *str);
		str++;
	}
	return (rst * sign);
}

void	ft_putnbr_base(int nbr, char *base, int *i, char *convert)
{
	int	n_base;

	n_base = ft_cal_base(base);
	if (n_base)
	{
		if (nbr < 0)
		{
			convert[*i] = '-';
			*i += 1;
			if (nbr / n_base != 0)
				ft_putnbr_base((nbr / n_base) * (-1), base, i, convert);
			ft_putnbr_base((nbr % n_base) * (-1), base, i, convert);
			return ;
		}
		if (nbr < n_base)
		{
			convert[*i] = base[nbr];
			*i += 1;
		}
		else
		{
			ft_putnbr_base(nbr / n_base, base, i, convert);
			ft_putnbr_base(nbr % n_base, base, i, convert);
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		rst;
	int		i;
	int		tmp;
	char	*converted;

	if (ft_cal_base(base_from) == 0 || ft_cal_base(base_to) == 0)
		return (NULL);
	rst = ft_atoi_base(nbr, base_from);
	i = 0;
	tmp = rst;
	if (tmp < 0)
	{
		i += 2;
		tmp = (tmp / ft_cal_base(base_to)) * (-1);
	}
	while (tmp > 0)
	{
		tmp /= ft_cal_base(base_to);
		i++;
	}
	converted = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	ft_putnbr_base(rst, base_to, &i, converted);
	converted[i] = '\0';
	return (converted);
}
