/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:55:49 by younko            #+#    #+#             */
/*   Updated: 2023/02/19 20:20:11 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	*ft_bzero(void *b, size_t len);
void	ft_putnbr(int nb);
void	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
char	*ft_strtok(char *str, char sepa);

#endif
