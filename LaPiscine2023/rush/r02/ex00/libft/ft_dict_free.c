/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:22:50 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 22:22:50 by seunmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dict_free(t_dict **dict)
{
	t_dict	*tmp;
	t_dict	*begin;

	begin = *dict;
	if (begin == NULL)
		return ;
	while (begin)
	{
		tmp = begin->next;
		free(begin->literal);
		free(begin);
		begin = tmp;
	}
}
