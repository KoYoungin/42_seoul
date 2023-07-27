/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:49:39 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 03:58:05 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

void	ft_free_map(char **map, t_rule *rule, t_sol *sol)
{
	int	i;

	i = 0;
	while (i < rule->row)
	{
		free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
	if (sol != NULL)
		free(sol);
}
