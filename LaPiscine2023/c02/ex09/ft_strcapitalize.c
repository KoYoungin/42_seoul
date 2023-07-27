/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:59:24 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 22:12:41 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_upperorlowdigit(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	c;
	int	wfir;

	i = -1;
	wfir = 1;
	while (str[++i] != '\0')
	{
		c = ft_is_upperorlowdigit(str[i]);
		if (c == 0)
			wfir = 1;
		else if (c == 1 && wfir == 1)
			wfir = 0;
		else if (c == 1 && wfir == 0)
			str[i] += 'a' - 'A';
		else if (c == 2 && wfir == 1)
		{
			str[i] -= 'a' - 'A';
			wfir = 0;
		}
		else if (c == 3)
			wfir = 0;
	}
	return (str);
}
