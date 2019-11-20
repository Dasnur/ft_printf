# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 17:36:24 by acarlett          #+#    #+#              #
#    Updated: 2019/11/18 17:19:32 by atote            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

DIR_O = obj

DIR_S = srcs

DIR_H = includes

LIBFT = libft

FILES = format_d_ld_lld_hd_hhd.c \
format_c.c \
format_str.c \
format_o8.c \
main.c \
format_p.c \
format_f.c \
format_x.c \

FILES_MAIN = srcs/format_d_ld_lld_hd_hhd.c \
srcs/format_c.c \
srcs/format_str.c \
srcs/format_o8.c \
srcs/main.c \
srcs/format_p.c \
srcs/format_f.c \
srcs/format_x.c \

SRCS = $(addprefix $(DIR_S)/,$(FILES))

OBJS = $(addprefix $(DIR_O)/,$(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(DIR_H)/libftprintf.h
	@mkdir -p $(DIR_O)
	@$(CC) -I $(DIR_H) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

main: fclean all
	@gcc $(FILES_MAIN) $(LIBFT)/libft.a
	@./a.out

test:
	@rm -rf test
	@gcc test.c libft/libft.a
	@./a.out

.PHONY: all clean fclean re
