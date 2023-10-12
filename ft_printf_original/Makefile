NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = printf.c \
printnum.c \
printp.c \
printstr.c \
printx.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS:.c=.o)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re