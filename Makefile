# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:37:14 by lnicosia          #+#    #+#              #
#    Updated: 2018/11/07 10:45:22 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 

OBJ = 

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRC)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
