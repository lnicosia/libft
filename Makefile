# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:37:14 by lnicosia          #+#    #+#              #
#    Updated: 2018/11/07 15:37:42 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src/ft_putchar.c src/ft_putstr.c src/ft_putendl.c src/ft_strlen.c src/ft_putnbr.c src/ft_strdup.c src/ft_strcpy.c src/ft_strncpy.c src/ft_strcat.c src/ft_strncat.c src/ft_strlcat.c src/ft_strstr.c src/ft_strnstr.c src/ft_strcmp.c src/ft_strncmp.c src/ft_atoi.c src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_toupper.c src/ft_tolower.c

OBJ = ft_putchar.o ft_putstr.o ft_putendl.o ft_strlen.o ft_putnbr.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.c ft_isalpha.c ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRC)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

main:
	gcc $(FLAGS) main.c $(SRC)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
