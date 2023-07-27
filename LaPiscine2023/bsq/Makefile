CC = gcc
CFLAGS = -Wall -Wextra -Werror 
TARGET = bsq
SRCS = main.c \
	   ft_make.c \
	   srcs/ft_parse_map.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strdup.c \
	   srcs/ft_atoi.c \
	   srcs/ft_alloc_map.c \
	   srcs/ft_check_rule.c \
	   srcs/ft_new_line.c \
	   srcs/ft_find_square.c \
	   srcs/ft_free.c \
	   srcs/ft_read_line.c \

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
