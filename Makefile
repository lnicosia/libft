# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:37:14 by lnicosia          #+#    #+#              #
#    Updated: 2018/11/07 12:34:55 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = src/ft_putchar.c src/ft_putstr.c src/ft_putendl.c src/ft_strlen.c src/ft_putnbr.c src/ft_strdup.c src/ft_strcpy.c src/ft_strncpy.c src/ft_strcat.c src/ft_strncat.c src/ft_strlcat.c src/ft_strstr.c

OBJ = ft_putchar.o ft_putstr.o ft_putendl.o ft_strlen.o ft_putnbr.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o

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
