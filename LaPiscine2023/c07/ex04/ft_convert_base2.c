/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:13:20 by younko            #+#    #+#             */
/*   Updated: 2023/02/28 14:04:27 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
		i++;
	return (i);
}

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
		if ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
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
