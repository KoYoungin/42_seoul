/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:44:33 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 22:06:21 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_rule	*make_rule(void)
{
	t_rule	*new;

	new = malloc(sizeof(t_rule));
	if (new == NULL)
		return (NULL);
	new->row = 0;
	new->col = 0;
	return (new);
}

t_sol	*make_sol(void)
{
	t_sol	*new;

	new = malloc(sizeof(t_sol));
	if (new == NULL)
		return (NULL);
	new->n = 0;
	new->x_r = 0;
	new->y_c = 0;
	return (new);
}
