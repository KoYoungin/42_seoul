CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = srcs/main.c \
	   srcs/ft_putstr.c \
	   srcs/ft_strlen.c \
	   srcs/ft_atoi.c \
	   srcs/ft_putnbr.c \
	   srcs/ft_cal.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) 

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all
