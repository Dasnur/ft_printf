# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:24:25 by acarlett          #+#    #+#              #
#    Updated: 2019/12/15 19:59:00 by acarlett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

FILES = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c \
ft_memset.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncpy.c ft_tolower.c \
ft_toupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_memalloc.c \
ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_putendl.c ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_itoa.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_foreach.c ft_range.c ft_match.c ft_map.c \

OBJ = $(patsubst %.c,%.o,$(FILES))

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

%.o: %.c
		@gcc $(FLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
