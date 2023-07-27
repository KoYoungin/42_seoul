/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:44:50 by younko            #+#    #+#             */
/*   Updated: 2023/02/14 02:57:28 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (size >= 2)
		ft_bubble_sort(tab, size);
}
/*#include <stdio.h>

int main(void)
{
	int a[5] = { 4, 5, 1, 9, 3};
	int i = 0;
	ft_bubble_sort(a,5);
	while (i<5)
	{
		printf("%d ",a[i]);
		i++;
	}
	return 0;
}*/
