/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:52:13 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 06:11:47 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	p;
	int	n;
	int	i;

	i = -1;
	p = 0;
	n = 0;
	if (length <= 0)
		return (1);
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			p++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			n++;
	}
	if (p == i || n == i)
		return (1);
	return (0);
}
