/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:04:22 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 22:14:23 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_program(char *name)
{
	while (*name != '\0')
	{
		ft_putchar(*name);
		name++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (0 - (int) *s2);
	else if (*s1 != '\0')
		return ((int) *s1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (++j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
		}
		i++;
	}
	i = 0;
	while (++i < argc)
		ft_print_program(argv[i]);
	return (0);
}
