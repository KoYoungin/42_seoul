/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoole <junsoole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:16:47 by junsoole          #+#    #+#             */
/*   Updated: 2023/02/12 19:45:45 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	rush(int a, int b);

int	ft_strtoi(char *str)
{
	int	sign;
	int	i;
	int	rst;

	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
		i++;
	rst = 0;
	while (str[i] != '\0')
	{
		rst *= 10;
		rst += str[i] - '0';
		i++;
	}
	return (sign * rst);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	i;

	i = 1;
	while (i < argc)
	{
		a = ft_strtoi(argv[i]);
		b = ft_strtoi(argv[i + 1]);
		rush(a, b);
		i += 2;
	}
	return (0);
}
