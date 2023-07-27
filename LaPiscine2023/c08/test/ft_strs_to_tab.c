/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:08:43 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 12:09:22 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		s_len;
	int		i;
	char	*dupstr;

	if (src == NULL)
		return (NULL);
	s_len = ft_strlen(src);
	dupstr = malloc(sizeof(char) * (s_len + 1));
	if (dupstr == NULL)
		return (NULL);
	i = -1;
	while (++i < s_len)
		dupstr[i] = src[i];
	dupstr[i] = '\0';
	return (dupstr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new;
	int			i;

	new = malloc(sizeof(t_stock_str) * (ac + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		
		new[i].size = ft_strlen(av[i]);
		new[i].copy = ft_strdup(av[i]);
		if (new[i].copy == NULL)
			return (NULL);
		new[i].str = av[i];
	}
	new[i].str = 0;
	return (new);
}
