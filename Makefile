# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 19:48:44 by lsampiet          #+#    #+#              #
#    Updated: 2024/06/09 23:33:50 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
C_FLAGS:= -Wextra -Wall -Werror
LIBFT= ./libs/libft
BIN= ./bin/
SRC_D= ./src/
CC= cc
HEADER_M= ./includes/pipex.h

LIBS= $(LIBFT)/libft.a
SRC= pipex.c \
	 utils.c \

SRC:= $(addprefix $(SRC_D),$(SRC))

INCLUDES= -I includes -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes -I $(LIBFT)/gnl/includes
C_OBJS= $(patsubst $(SRC_D)%.c, $(BIN)%.o, $(SRC))

all: $(NAME)
	echo "Mandatory part OK!🎉"

libft:
	echo "Compiling LIBFT..."
	make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

$(BIN)%.o: $(SRC_D)%.c
	mkdir -p $(BIN)
	$(CC) $(C_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): $(C_OBJS) libft
	echo "Creating $(NAME)"
	$(CC) $(C_OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

clean:
	echo "Cleaning objects..."
	rm -rf $(BIN)
	make fclean -C $(LIBFT) --no-print-directory
	echo "Cleaning build..."
	echo "All done!✨"

fclean: clean
	echo "Cleaning executables..."
	rm -rf $(NAME)
	echo "All done!✨"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus

.SILENT: