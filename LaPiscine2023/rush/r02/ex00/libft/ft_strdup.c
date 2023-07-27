/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:24:05 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:25:35 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
