/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:47:43 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 19:47:45 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strdup(const char *str)
{
	int		lenght;
	char	*new_string;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	lenght = ft_strlen(str);
	new_string = malloc(sizeof(char) * lenght);
	while (i < lenght)
	{
		new_string[i] = str[i];
		i++;
	}
	return (new_string);
}
