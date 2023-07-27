/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:07:34 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 23:17:59 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int	check_op(char *oper, char *o)
{
	if (ft_strlen(oper) != 1)
		return (0);
	*o = oper[0];
	if (*o != '+' && *o != '-' && *o != '*' && *o != '/' && *o != '%')
		return (0);
	return (1);
}

void	ft_cal(int a, int b, char o)
{
	int		(*tab[5])(int, int);

	tab[0] = add;
	tab[1] = sub;
	tab[2] = mul;
	tab[3] = div;
	tab[4] = mod;
	if (o == '+')
		ft_putnbr(tab[0](a, b));
	if (o == '-')
		ft_putnbr(tab[1](a, b));
	if (o == '*')
		ft_putnbr(tab[2](a, b));
	if (o == '/' && b != 0)
		ft_putnbr(tab[3](a, b));
	if (o == '/' && b == 0)
		ft_putstr("Stop : division by zero");
	if (o == '%' && b != 0)
		ft_putnbr(tab[4](a, b));
	if (o == '%' && b == 0)
		ft_putstr("Stop : modulo by zero");
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	o;

	if (argc == 4)
	{
		if (check_op(argv[2], &o))
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			ft_cal(a, b, o);
		}
		else
			ft_putstr("0\n");
	}
}
