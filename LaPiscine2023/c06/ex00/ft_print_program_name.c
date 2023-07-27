/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:48:52 by younko            #+#    #+#             */
/*   Updated: 2023/02/22 21:52:26 by younko           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_print_program(argv[0]);
	return (0);
}
