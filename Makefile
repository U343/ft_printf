# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wanton <wanton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 14:07:05 by wanton            #+#    #+#              #
#    Updated: 2020/03/11 14:58:45 by wanton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADER = includes
LIB_HEADER = libft/includes/

SOURCES =	ft_printf.c \
			parser.c \
			s_flag.c \
			d_flag.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c main.c
	mkdir -p $(DIR_O)
	$(CC) $(FLAGS) -I $(HEADER)  -I $(LIB_HEADER) -o $@ -c $<
	gcc -I include -o prog main.c -L. -lftprintf

norme:
	norminette ./libft/
	echo
	norminette ./$(HEADER)/ ./$(LIB_HEADER)/
	echo
	norminette ./$(DIR_S)/

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all