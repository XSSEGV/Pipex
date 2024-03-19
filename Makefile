NAME = pipex
BONUS_NAME = pipex_bonus

CC = cc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRCS = src/pipex.c src/utils.c src/utils2.c
SRCS_BONUS = src_bonus/pipex_bonus.c src_bonus/utils_bonus.c src_bonus/utils_bonus2.c

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)

bonus: $(SRCS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(BONUS_NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(NAME) $(BONUS_NAME)
	make clean -C libft

fclean: clean
	make fclean -C libft

re: fclean all
