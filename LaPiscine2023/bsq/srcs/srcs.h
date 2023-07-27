/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younko <younko@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:25:01 by younko            #+#    #+#             */
/*   Updated: 2023/03/01 22:32:47 by younko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_rule
{
	int		row;
	int		col;
	char	empt;
	char	obst;
	char	full;
}	t_rule;
typedef struct s_sol
{
	int		n;
	int		x_r;
	int		y_c;
}	t_sol;
typedef struct s_all
{
	char	**map;
	t_rule	*rule;
	t_sol	*sol;
}	t_all;
char	**ft_parse_map(t_rule *rule, char **map, char *map_path);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int n);
int		ft_alloc_map(char *line, char **map, t_rule *rule, int r);
int		ft_atoi(const char *str);
int		ft_check_rule(t_rule *rule, char *line);
char	*new_line(char *line);
int		ft_find_square(t_rule *rule, char **map, t_sol *sol);
void	ft_free_map(char **map, t_rule *rule, t_sol *sol);
char	*plus_line(char *line, char *buf);
char	*ft_read_rule(char *map_path, t_rule *rule, int *f);

#endif
