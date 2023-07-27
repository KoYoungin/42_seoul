/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:22:26 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:22:09 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line(char *str, int *start_i)
{
	int	j;

	j = 0;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	while (str[j] == ' ')
		j++;
	if (str[j] != ':')
		return (0);
	else
		j++;
	while (str[j] == ' ')
		j++;
	*start_i = j;
	while (str[j] != '\0')
	{
		if (str[j] < 32 || str[j] > 126)
			return (0);
		j++;
	}
	return (1);
}

int	check_dict(t_dict *dict, int n)
{
	while (dict != NULL)
	{
		if (dict->n == n)
			return (0);
		dict = dict->next;
	}
	return (1);
}

int	check_num(int n, int *plus)
{
	int	tmp;
	int	j;

	tmp = n;
	if (tmp >= 1000)
	{
		j = 0;
		while (tmp > 0)
		{
			if (tmp % 1000 != 0)
				return (0);
			tmp /= 1000;
			j++;
			if (tmp == 1)
				break ;
		}
		*plus = j;
	}
	else
		*plus = 0;
	return (1);
}

int	alloc_dict(char *str, t_dict **dict)
{
	int		n;
	int		plus;
	int		i;
	char	*tmp;

	n = ft_atoi(str);
	if (check_num(n, &plus) == 0 || n < 0)
		return (0);
	if (plus == 0 && check_dict(*dict, n) == 0)
		return (0);
	if (check_line(str, &i) == 0)
		return (0);
	tmp = ft_strdup(str + i);
	if (tmp == NULL)
		return (0);
	if (ft_push_front(dict, n, plus, tmp) == 0)
		return (0);
	return (1);
}
