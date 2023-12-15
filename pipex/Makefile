NAME = pipex.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT_NAME = libft.a
SRCS = pipex.c \
getpath.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)/$(LIBFT_NAME) $(LIBFT_NAME)
		mv $(LIBFT_NAME) $@
		ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS:.c=.o)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re