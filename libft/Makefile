# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedavis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 16:24:15 by bedavis           #+#    #+#              #
#    Updated: 2020/01/10 12:19:26 by bedavis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strlen.c ft_isalpha.c ft_islower.c ft_isupper.c ft_isdigit.c ft_memcmp.c \
	  ft_strcpy.c ft_bzero.c ft_tolower.c ft_toupper.c ft_memset.c ft_strcmp.c \
	  ft_strstr.c ft_strncmp.c ft_isprint.c ft_isalnum.c ft_isascii.c ft_strncpy.c \
	  ft_strdup.c ft_memcpy.c ft_memccpy.c ft_isspace.c ft_memchr.c ft_strchr.c \
	  ft_memmove.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strnstr.c \
	  ft_atoi.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_striter.c ft_striteri.c ft_strclr.c \
	  ft_strmap.c ft_memalloc.c ft_strnew.c ft_memdel.c ft_strdel.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_itoa.c ft_strtrim.c \
	  ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstaddend.c ft_lstmap.c ft_strtolower.c ft_strtoupper.c \
	  ft_get_next_line.c ft_itoall.c ft_itoa_base.c ft_strpos.c \
	  ft_unsigned_itoa_base.c
OBJ = $(SRC:.c=.o)
HEAD = -I ./includes

all: $(NAME)

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(NAME):
			@gcc -Wall -Wextra -Werror -c $(SRC) $(HEAD)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)

clean:
			@/bin/rm -f $(OBJ)

fclean: clean
			@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
