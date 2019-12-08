# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 17:36:24 by acarlett          #+#    #+#              #
#    Updated: 2019/12/08 19:09:22 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

DIR_O = obj

DIR_S = srcs

DIR_H = includes

LIBFT = libft

FILES = format_d_u.c \
format_d_u_convert_toint.c \
format_d_u_convert_tounsigned.c \
format_d_u_first.c \
format_d_u_second.c \
format_c.c \
format_str.c \
format_str_colour.c \
format_o8.c \
format_f.c \
format_f_help.c \
format_f_printing.c \
format_f_sup_printing.c \
format_f_sup_printing2.c \
format_f_mantiss.c \
format_f_sup_mant.c \
main.c \
main_2.c \
main_3.c \
main_4.c \
format_p.c \
format_p_help.c \
format_x.c \
format_x_second.c \
between.c \
for_star.c \
format_b.c \

FILES_MAIN = srcs/format_d_u.c \
srcs/format_c.c \
srcs/format_str.c \
srcs/format_o8.c \
srcs/format_f.c \
srcs/format_f_printing.c \
srcs/format_f_sup_printing.c \
srcs/format_f_sup_printing2.c \
srcs/format_f_mantiss.c \
srcs/format_f_sup_mant.c \
srcs/format_d_u_convert_toint.c \
srcs/format_d_u_convert_tounsigned.c \
srcs/format_d_u_first.c \
srcs/format_d_u_second.c \
srcs/main.c \
srcs/main_2.c \
srcs/main_3.c \
srcs/main_4.c \
srcs/format_p.c \
srcs/format_x.c \
srcs/format_x_second.c \
srcs/for_star.c \
srcs/between.c \
srcs/format_b.c \
srcs/format_p_help.c \
srcs/format_str_colour.c \
srcs/format_f_help.c \

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