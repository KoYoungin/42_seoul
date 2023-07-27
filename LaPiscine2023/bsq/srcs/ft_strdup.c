/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:50:09 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 19:59:04 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs.h"

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

char	*ft_strndup(char *src, int n)
{
	char	*dup;
	int		i;

	if (src == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
