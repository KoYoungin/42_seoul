CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
SRCS = main.c \
	libft/alloc_dict.c\
	libft/ft_atoi.c\
	libft/ft_dict_free.c\
	libft/ft_dict_open.c\
	libft/ft_dict_sort.c\
	libft/ft_print_literal.c\
	libft/ft_push_front.c\
	libft/ft_putstr.c\
	libft/ft_strdup.c\
	libft/ft_strlen.c\
	libft/ft_num_check.c\
	libft/ft_pow.c\
	libft/find_literal.c\
	libft/num_len.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

.c:	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

.PHONY: all clean fclean
