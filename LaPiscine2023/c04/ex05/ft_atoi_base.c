/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:43:31 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 22:32:23 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if ((str[i] >= '\b' && str[i] <= '\r') || str[i] == ' ')
			return (0);
		j = i;
		while (str[++j] != '\0')
			if (str[i] == str[j])
				return (0);
		base++;
		i++;
	}
	return (base);
}

int	ft_is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(const char *str, char *base)
{
	int	sign;
	int	rst;
	int	n_base;

	rst = 0;
	sign = 1;
	while ((*str >= '\b' && *str <= '\r') || *str == ' ')
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
		rst *= n_base;
		rst += ft_is_in_base(base, *str);
		str++;
	}
	return (rst * sign);
}
