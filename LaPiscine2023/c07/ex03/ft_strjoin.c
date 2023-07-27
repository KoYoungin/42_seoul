/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:04:35 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 22:40:05 by younko           ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	cal_size(int size, char **strs, int sep_len)
{
	int	i;
	int	len;

	len = sep_len * (size - 1);
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]);
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_size;
	int		i;
	char	*joined_str;

	if (size == 0)
	{
		joined_str = malloc(sizeof(char));
		joined_str[0] = '\0';
		return (joined_str);
	}
	str_size = cal_size(size, strs, ft_strlen(sep));
	joined_str = (char *)malloc(sizeof(char) * str_size);
	if (joined_str == NULL)
		return (0);
	joined_str[0] = '\0';
	i = -1;
	while (++i < size - 1)
	{
		ft_strcat(joined_str, strs[i]);
		ft_strcat(joined_str, sep);
	}
	ft_strcat(joined_str, strs[i]);
	joined_str[str_size - 1] = '\0';
	return (joined_str);
}
