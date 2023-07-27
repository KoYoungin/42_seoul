/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:24:36 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:33:23 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	numeric(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[++i] != '\0')
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	check_argv(int argc, char **argv, char **num, char **dict_read)
{
	int	i;

	i = -1;
	if (argc == 2 && argv[1][0] != '\0')
	{
		if (ft_atoi(argv[1]) < 0)
			return (0);
		*num = argv[1];
		*dict_read = "dict/numbers.dict";
	}
	else if (argc == 3 && argv[2][0] != '\0')
	{
		if (ft_atoi(argv[2]) < 0)
			return (0);
		*dict_read = argv[1];
		*num = argv[2];
	}
	if (numeric(*num) == 0)
		return (0);
	return (1);
}	

void	find_zero(int n, t_dict *dict)
{
	char	*l;

	l = find_literal(n, dict);
	if (l == NULL)
		ft_putstr("Error");
	else
		ft_putstr(l);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict_path;
	t_dict	*dict;

	if (check_argv(argc, argv, &num, &dict_path) == 0)
	{
		ft_putstr("Error");
	}
	else
	{
		dict = 0;
		if (ft_dict_open(&dict, dict_path) != 1)
			ft_putstr("Dict Error");
		else
		{
			if (ft_atoi(num) == 0)
				find_zero(0, dict);
			else if (ft_print_literal(num, dict) == 0)
				ft_putstr("Error");
		}
		ft_dict_free(&dict);
	}
	ft_putstr("\n");
	return (0);
}
