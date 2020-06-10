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

#Source files
SOURCES =	ft_printf.c \
			parser.c \
			s_flag.c \
			d_flag.c \
			c_flag.c \
			pr_flag.c \
			p_flag.c \
			f_flag.c \
			d_flag_assist.c \
			help_functions.c \
			init_functions.c \
			f_flag_func.c

#Compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Ft library
LIBFT = libft
LIBFT_DIRECTORY = ./libft/
LIB_HEADER = $(LIBFT_DIRECTORY)includes/
LIBFT_LINK = -L $(LIBFT_DIRECTORY) -l ft

#Directories
DIR_S = ./src/
DIR_O = ./obj/
HEADER = ./includes/

#Source
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

#Object files
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

INCLUDES = -I $(HEADER) -I $(LIB_HEADER)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)printf.h
		@mkdir -p $(DIR_O)
		@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<
		@echo "\n$(NAME): $(GREEN)object file was created$(RESET)"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@make -C $(LIBFT_DIRECTORY)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME): $(GREEN)Creating Printf...$(RESET)"

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/ ./$(LIB_HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@rm -rf $(DIR_O)
	@echo "$(NAME): $(RED)$(DIR_O) was deleted$(RESET)"
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@make fclean -C $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"

re: fclean all

.PHONY: all obj norme clean fclean re
