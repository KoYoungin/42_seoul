/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:22:15 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 06:09:22 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*rst;
	int	i;

	rst = malloc(sizeof(int) * length);
	if (rst == NULL)
		return (rst);
	i = -1;
	while (++i < length)
		rst[i] = (*f)(tab[i]);
	return (rst);
}
