CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = srcs/ft_putstr.c \
	   srcs/ft_putchar.c \
	   srcs/ft_swap.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -I includes -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
