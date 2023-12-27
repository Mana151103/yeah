NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT_NAME = libft.a
PRINTF_DIR = ft_printf
PRINTF_NAME = libftprintf.a
SRCS = pipe.c \
getpath.c \
set_pipex.c \
pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		make -C $(PRINTF_DIR)
		cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
		cp $(PRINTF_DIR)/$(PRINTF_NAME) $(NAME)
		$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re