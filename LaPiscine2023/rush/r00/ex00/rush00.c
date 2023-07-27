/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsoole <junsoole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:56:18 by junsoole          #+#    #+#             */
/*   Updated: 2023/02/12 19:50:04 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

void	ft_print(int r, char fi, char mi, char la)
{
	int	i;

	i = 0;
	while (i < r)
	{
		if (i == 0)
			ft_putchar(fi);
		else if (i == r - 1)
			ft_putchar(la);
		else
			ft_putchar(mi);
		i++;
	}
	if (i == r && i > 0)
		ft_putchar('\n');
}

void	rush(int a, int b)
{
	int	i;

	i = 0;
	while (i < b)
	{
		if (i == 0)
			ft_print(a, 'o', '-', 'o');
		else if (i == b - 1)
			ft_print(a, 'o', '-', 'o');
		else
			ft_print(a, '|', ' ', '|');
		i++;
	}
}
