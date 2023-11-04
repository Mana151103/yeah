NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs/
OBJS_DIR = $(SRCS_DIR)
INCLUDES_DIR = includes/
SRCS = $(addprefix $(SRCS_DIR), ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re