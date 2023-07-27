CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = rush-01
SRCS = r1_main.c \
		r1_solver.c \
		r1_setline.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_putnbr.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strtok.c 

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

