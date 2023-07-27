/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_literal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:17:10 by younko            #+#    #+#             */
/*   Updated: 2023/02/26 23:17:13 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_literal(int nb, t_dict *dict)
{
	t_dict	*cur_dict;

	cur_dict = dict;
	if (nb > cur_dict->n)
		return (find_literal(nb, cur_dict->next));
	else if (nb == cur_dict->n)
	{
		return (cur_dict->literal);
	}
	else
		return (NULL);
}
