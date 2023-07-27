/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:24:41 by younko            #+#    #+#             */
/*   Updated: 2023/02/26 23:24:43 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nb, int power)
{
	int	rst;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	rst = 1;
	i = 0;
	while (i++ < power)
		rst *= nb;
	return (rst);
}
