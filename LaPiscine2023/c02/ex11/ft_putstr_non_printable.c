/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:09:27 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 19:14:23 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_hex(char *hex)
{
	int	i;

	i = -1;
	while (++i < 10)
		hex[i] = i + '0';
	while (i < 16)
	{
		hex[i] = i - 10 + 'a';
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;
	char			hex[16];

	i = -1;
	ft_hex(hex);
	while (str[++i] != '\0')
	{
		if (ft_is_printable(str[i]) == 1)
			ft_putchar(str[i]);
		else
		{
			c = (unsigned char) str[i];
			ft_putchar('\\');
			ft_putchar(hex[(int)c / 16]);
			ft_putchar(hex[(int)c % 16]);
		}
	}
}
