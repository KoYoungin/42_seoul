/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:18 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 19:27:41 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_print_first(long long a)
{
	char	addr[16];
	char	hex[16];
	int		i;

	ft_hex(hex);
	i = 0;
	while (a > 0)
	{
		addr[i] = hex[a % 16];
		a /= 16;
		i++;
	}
	while (i < 16)
	{
		addr[i] = '0';
		i++;
	}
	i = 16;
	while (--i >= 0)
		write(1, &addr[i], 1);
	write(1, ": ", 2);
}

void	ft_print_second(char *str, int size)
{
	int		i;
	char	hex[16];

	ft_hex(hex);
	i = -1;
	while (++i < size)
	{
		write(1, &hex[(int)str[i] / 16], 1);
		write(1, &hex[(int)str[i] % 16], 1);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_third(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*cur_adr;
	int		cur_size;
	int		t_size;

	if (size == 0)
		return (addr);
	cur_adr = (char *)addr;
	t_size = size;
	while ((void *)cur_adr < addr + size)
	{
		if (t_size >= 16)
		{
			t_size -= 16;
			cur_size = 16;
		}
		else
			cur_size = t_size;
		ft_print_first((long long)cur_adr);
		ft_print_second(cur_adr, cur_size);
		ft_print_third(cur_adr, cur_size);
		cur_adr += 16;
	}
	return (addr);
}
