/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:26:54 by younko            #+#    #+#             */
/*   Updated: 2023/02/14 01:41:12 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
/*#include <stdio.h>

int main(void)
{
	int a[7] = {1,2,3,4,5,6,7};
	int i = 0;

	ft_rev_int_tab(a,7);
	while (i<7)
	{
		printf("%d, ",a[i]);
		i++;
	}
	return 0;
}*/
