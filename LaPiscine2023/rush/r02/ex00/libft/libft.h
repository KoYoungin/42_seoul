/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunmoon <seunmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:24:26 by seunmoon          #+#    #+#             */
/*   Updated: 2023/02/26 23:02:58 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	int				n;
	int				plus;
	char			*literal;
	struct s_dict	*next;
}	t_dict;
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_putstr(char *str);
void	ft_putstrn(char *str);
int		alloc_dict(char *str, t_dict **dict);
void	ft_dict_sort(t_dict **dict);
int		ft_dict_open(t_dict **dict, char *dictpath);
int		ft_print_literal(char *n, t_dict *dict);
int		ft_push_front(t_dict **dict, int n, int plus, char *literal);
void	ft_dict_free(t_dict **dict);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int n);
int		check_len(char *nb);
char	*find_literal(int nb, t_dict *dict);
int		num_len(int n);
int		ft_pow(int nb, int power);

#endif
