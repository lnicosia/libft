# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 15:56:21 by lnicosia          #+#    #+#              #
#    Updated: 2022/06/15 11:53:47 by lnicosia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes
BIN_DIR = .
PRINTF_DIR = ft_printf
PRINTF_SRC_DIR = $(addprefix $(PRINTF_DIR)/, src)
PRINTF_INC_DIR = $(addprefix $(PRINTF_DIR)/, inc)
PRINTF_OBJ_DIR = $(addprefix $(PRINTF_DIR)/, obj)
OPTI_FLAGS = -O3

SRC_RAW = ft_memccpy.c ft_memcpy.c ft_memset.c ft_bzero.c ft_memmove.c \
		  ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		  ft_putchar_fd.c ft_putchar.c ft_putstr.c ft_putstr_fd.c ft_strlen.c \
		  ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strchr.c \
		  ft_strstr.c ft_strnstr.c ft_atoi.c ft_strcmp.c ft_strncmp.c \
		  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		  ft_strmapi.c ft_strnequ.c ft_strequ.c ft_strsub.c ft_strjoin.c \
		  ft_strtrim.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		  ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstlen.c ft_lstpushback.c \
		  ft_abs.c get_next_line.c ft_strjoin_free.c ft_min.c ft_max.c \
		  ft_fmin.c ft_fmax.c ft_count.c ft_fabs.c ft_atoi_base.c time_utils.c \
		  ft_clamp.c ft_fclamp.c ft_fclamp.c ft_atof.c ft_getlen.c \
		  ft_sitoa.c ft_realloc.c ft_getsize.c ft_delindex.c ft_perror.c \
		  ft_lstcontains.c ft_lstpopfront.c ft_lstdelfront.c \
		  ft_lstdelnode.c ft_convert_base.c ft_ishexa.c tpool.c \
		  tpool_job.c init_tpool.c free_tpool.c skip_chars.c \
		  check_chars.c ft_rmchar.c ft_dlstnew.c ft_dlstdelfront.c \
		  ft_dlstinsert.c ft_dlstbackward.c ft_dlstforward.c \
		  ft_dlstlen.c ft_stricmp.c print_bits.c ft_strbegin.c \
		  ft_ceil.c ft_centiceil.c is_a_special_char.c replace_char.c \
		  contains_special_chars.c ft_dlist_to_array.c print_packet.c \
		  reverse_bits.c reverse_endian.c ft_labs.c checksum.c \
		  ft_getopt.c ft_getopt_silent.c is_arg_an_opt.c \

SRC_SIZE = $(shell ls src | wc -l)

HEADERS = libft.h tpool.h get_next_line.h

PRINTF_SRC_RAW = ft_printf.c ft_dprintf.c base_utils.c parse_colors.c \
				 parse_flags.c parse_functions.c pf_atoi.c pf_float_padding.c \
				 pf_invalid.c pf_putaddr.c pf_putchar.c pf_putfloat.c \
				 pf_putlong_base.c pf_putnbr.c pf_putnbr_base.c \
				 pf_putpercent.c pf_putstr.c pf_putunbr.c pf_strnequ.c \
				 put_padding.c putfloat_utils.c ft_snprintf.c fill_buffer.c \
				 custom_error.c custom_invalid.c ft_vprintf.c ft_vsnprintf.c \
				 ft_noprintf.c ft_novprintf.c ft_sprintf.c ft_vsprintf.c \
				 ft_bprintf.c \

PRINTF_SRC_SIZE = $(shell ls ft_printf/src | wc -l)

PRINTF_HEADERS = ft_printf.h base_utils.h color.h put_padding.h

SRC = $(addprefix $(SRC_DIR)/, $(SRC_RAW))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_RAW:.c=.o))
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(HEADERS))

PRINTF_SRC = $(addprefix $(PRINTF_SRC_DIR)/, $(PRINTF_SRC_RAW))
PRINTF_OBJ = $(addprefix $(PRINTF_OBJ_DIR)/, $(PRINTF_SRC_RAW:.c=.o))

ifeq ($(OS), Windows_NT)
	OPTI_FLAGS = -O3
else
    OPTI_FLAGS = -O3
endif

CFLAGS = -Wall -Wextra -Werror -Wpadded -I $(INCLUDES_DIR) -I $(PRINTF_INC_DIR) \
			-Wno-unused-result -Wno-misleading-indentation \
			$(OPTI_FLAGS) \
			#-fsanitize=address -g3 \

# Color declarations
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

all: $(BIN_DIR)/$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(PRINTF_OBJ_DIR):
	@mkdir -p $(PRINTF_OBJ_DIR)

I = 1
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@printf $(YELLOW)"[$(I)/$(SRC_SIZE)] Compiling $<\n"$(RESET)
	$(eval I=$(shell echo $$(($(I) + 1))))
	gcc -c $< -o $@ $(CFLAGS)

PI = 1
$(PRINTF_OBJ_DIR)/%.o: $(PRINTF_SRC_DIR)/%.c
	@printf $(YELLOW)"[$(PI)/$(PRINTF_SRC_SIZE)] Compiling $<\n"$(RESET)
	$(eval PI=$(shell echo $$(($(PI) + 1))))
	gcc -c $< -o $@ $(CFLAGS)

$(BIN_DIR)/$(NAME): $(OBJ_DIR) $(OBJ) $(PRINTF_OBJ_DIR) $(PRINTF_OBJ)
	@printf "\e[0;36m[INFO] Linking ${NAME}\e[0m\n"
	ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)
	ranlib $(NAME)
	@printf ${GREEN}"[INFO] Linked $(NAME) with success\n"${RESET}

clean:
	@printf ${CYAN}"[INFO] Removing objs from the libft\n"${RESET}
	rm -rf $(OBJ_DIR)
	rm -rf $(PRINTF_OBJ_DIR)

fclean: clean
	@printf ${CYAN}"[INFO] Removing $(NAME) from the libft\n"${RESET}
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean libft
