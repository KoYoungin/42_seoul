#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

#include <stdio.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
} t_stock_str;
#endif
