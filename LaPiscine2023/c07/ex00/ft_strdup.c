/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:11:17 by younko            #+#    #+#             */
/*   Updated: 2023/02/27 15:28:31 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
