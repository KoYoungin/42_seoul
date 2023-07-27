/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:40:24 by younko            #+#    #+#             */
/*   Updated: 2023/03/02 20:41:06 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

#endif
