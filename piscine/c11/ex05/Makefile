NAME = do-op
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = door_open1.c door_open2.c
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<

all:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
