/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:23:35 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 22:23:37 by seunmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*create_t_dict(int n, int plus, char *literal)
{
	t_dict	*new;

	new = NULL;
	new = (t_dict *)malloc(sizeof(t_dict));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->plus = plus;
	new->literal = (char *)malloc(sizeof(char) * (ft_strlen(literal) + 1));
	if (new->literal == NULL)
		return (NULL);
	new->literal = literal;
	new->next = NULL;
	return (new);
}

int	ft_push_front(t_dict **dict, int n, int plus, char *literal)
{
	t_dict	*front;

	front = create_t_dict(n, plus, literal);
	if (dict != NULL)
	{
		if (front == NULL)
			return (0);
		front->next = *dict;
		*dict = front;
	}
	else
	{
		*dict = front;
		if (*dict == NULL)
			return (0);
	}
	return (1);
}
