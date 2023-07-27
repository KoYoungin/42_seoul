/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:23:21 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 22:23:21 by seunmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(t_dict *a, t_dict *b)
{
	int		n;
	int		plus;
	char	*literal;

	n = a->n;
	plus = a->plus;
	literal = a->literal;
	a->n = b->n;
	a->plus = b->plus;
	a->literal = b->literal;
	b->n = n;
	b->plus = plus;
	b->literal = literal;
}

void	ft_dict_sort(t_dict **dict)
{
	t_dict	*i;
	t_dict	*j;

	i = *dict;
	while (i != NULL)
	{
		j = *dict;
		while (j->next != NULL)
		{
			if (j->n > j->next->n)
				ft_swap(j, j->next);
			j = j->next;
		}
		i = i->next;
	}
}
