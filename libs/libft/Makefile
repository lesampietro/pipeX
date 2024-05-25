# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 21:58:01 by lsampiet          #+#    #+#              #
#    Updated: 2024/03/27 21:38:33 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a

C_SOURCE= ft_isalnum.c \
				 ft_atoi.c \
				 ft_bzero.c \
				 ft_calloc.c \
				 ft_isalpha.c \
				 ft_isascii.c \
				 ft_isdigit.c \
				 ft_isprint.c \
				 ft_itoa.c \
				 ft_memchr.c \
				 ft_memcmp.c \
				 ft_memcpy.c \
				 ft_memmove.c \
				 ft_memset.c \
				 ft_putchar_fd.c \
				 ft_putendl_fd.c \
				 ft_putnbr_fd.c \
				 ft_putstr_fd.c \
				 ft_split.c \
				 ft_strchr.c \
				 ft_strdup.c \
				 ft_striteri.c \
				 ft_strjoin.c \
				 ft_strlcat.c \
				 ft_strlcpy.c \
				 ft_strlen.c \
				 ft_strmapi.c \
				 ft_strncmp.c \
				 ft_strnstr.c \
				 ft_strrchr.c \
				 ft_strtrim.c \
				 ft_substr.c \
				 ft_tolower.c \
				 ft_toupper.c

C_BONUS= ft_lstnew_bonus.c \
				 ft_lstadd_front_bonus.c \
				 ft_lstsize_bonus.c \
				 ft_lstlast_bonus.c \
				 ft_lstadd_back_bonus.c \
				 ft_lstdelone_bonus.c \
				 ft_lstclear_bonus.c \
				 ft_lstiter_bonus.c \
				 ft_lstmap_bonus.c

C_NEW= ../gnl/get_next_line.c \
				 ../gnl/get_next_line_utils.c \
				 ../ft_printf/ft_printf.c \
				 ../ft_printf/ft_printf_utils.c \
				 ../ft_printf/ft_printf_utils02.c \

HEADER=./

C_OBJ=$(C_SOURCE:%.c=%.o)

BONUS_OBJ=$(C_BONUS:%.c=%.o)

NEW_OBJ=$(C_NEW:%.c=%.o)

CC= cc

C_FLAGS= -Wall -Werror -Wextra

$(NAME): $(C_OBJ)

all: $(NAME)
	@echo "LIBFT has been compiled 😇"

bonus: $(BONUS_OBJ)
	@echo "BONUS has been compiled 😁"

new: $(NEW_OBJ)
	@echo "NEW FUNCTIONS have been compiled 😍"

%.o: %.c
	@echo "Compiling $(notdir $<) ..."
	$(CC) $(C_FLAGS) -I $(HEADER) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	@echo "Removing LIBFT objects..."
	rm -f $(C_OBJ) $(BONUS_OBJ)
	@echo "Removing GNL & PRINTF objects..."
	rm -f $(NEW_OBJ)
	@echo "All done!👍"

fclean: clean
	@echo "Removing $(NAME)..."
	rm -f $(NAME)
	@echo "All done!👍"

re: fclean all

.PHONY= clean fclean re all bonus