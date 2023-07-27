/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:11:41 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 14:10:05 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
		i++;
	}
	if (i != n)
	{
		if (*s2 != '\0')
			return (0 - (int) *s2);
		else if (*s1 != '\0')
			return ((int) *s1);
	}
	return (0);
}
