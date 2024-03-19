# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 20:08:20 by aylamgha          #+#    #+#              #
#    Updated: 2024/03/06 20:26:44 by aylamgha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = ft_atoi.c ft_isprint.c ft_memset.c \
      ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_calloc.c \
      ft_itoa.c ft_strlen.c ft_strtrim.c ft_isalnum.c \
      ft_memchr.c ft_strchr.c ft_substr.c ft_isalpha.c \
      ft_memcmp.c ft_strdup.c ft_striteri.c ft_tolower.c \
      ft_isascii.c ft_memcpy.c ft_strjoin.c ft_strncmp.c \
      ft_toupper.c ft_isdigit.c ft_memmove.c ft_strlcat.c \
      ft_strnstr.c ft_split.c ft_strmapi.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c get_next_line_bonus.c

BONUS = ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
        ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
        ft_lstdelone_bonus.c ft_lstclear_bonus.c \
        ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BOBJ) $(OBJ)
	@ar rc $(NAME) $(BOBJ) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ) $(BOBJ) #get_next_line.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all
