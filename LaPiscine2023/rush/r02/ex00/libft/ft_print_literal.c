/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_literal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:23:29 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:16:53 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_plus(int plus, t_dict *dict)
{
	char	*liter;

	liter = find_literal(ft_pow(1000, plus), dict);
	if (liter == NULL)
		return (0);
	ft_putstrn(liter);
	return (1);
}

int	valid_ten(char *n, t_dict *d)
{
	int		i;
	int		ten;
	char	*l;

	i = ft_atoi(n);
	l = find_literal(i, d);
	if (l != NULL)
	{
		ft_putstrn(l);
		return (1);
	}
	ten = i / 10;
	l = find_literal(ten * 10, d);
	if (l == NULL)
		return (0);
	ft_putstrn(l);
	l = find_literal(i % 10, d);
	if (l != NULL)
	{
		ft_putstrn(l);
		return (1);
	}
	return (0);
}

int	print_three(char *three, t_dict *dict, int size)
{
	int		v;
	int		i;
	char	*l;

	i = 0;
	if (size == 3)
	{
		l = find_literal(three[0] - '0', dict);
		if (l == NULL)
			return (0);
		ft_putstrn(l);
		l = find_literal(ft_pow(10, 2), dict);
		if (l == NULL)
			return (0);
		ft_putstrn(l);
		i++;
	}
	if (ft_atoi(three) % 100 != 0)
	{
		v = valid_ten(three + i, dict);
		if (v == 0)
			return (0);
	}
	return (1);
}

int	ft_print_literal(char *n, t_dict *dict)
{
	int		plus;
	int		i;

	plus = (num_len(ft_atoi(n)) - 1) / 3;
	i = num_len(ft_atoi(n)) - plus * 3;
	if (*n == '+')
		n++;
	if (ft_atoi(n) > 1000)
	{
		ft_print_literal(ft_strndup(n, i), dict);
		if (ft_print_plus(plus, dict) == 0)
			return (0);
		if (ft_atoi(n) % 1000 != 0)
			ft_print_literal(n + i, dict);
	}
	else
		if (print_three(n, dict, i) == 0)
			return (0);
	return (1);
}
