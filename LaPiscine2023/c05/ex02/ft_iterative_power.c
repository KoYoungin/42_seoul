/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:01:58 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 16:07:02 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
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
