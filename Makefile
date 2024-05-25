# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 19:48:44 by lsampiet          #+#    #+#              #
#    Updated: 2024/05/25 13:44:41 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
NAME_BONUS= pipex_bonus
C_FLAGS:= -Wextra -Wall -Werror
LIBFT= ./libs/libft
BIN= ./bin/
# BIN_BONUS= ./bin_bonus/
SRC_D= ./src/
# SRC_B= ./src_bonus/

CC= cc
HEADER_M= ./includes/pipex.h
# HEADER_B= ./includes/pipex_bonus.h \

LIBS= $(LIBFT)/libft.a
SRC= pipex.c \

SRC:= $(addprefix $(SRC_D),$(SRC))
# BONUS:= $(addprefix $(SRC_B),$(BONUS))

INCLUDES= -I includes -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes -I $(LIBFT)/gnl/includes
C_OBJS= $(patsubst $(SRC_D)%.c, $(BIN)%.o, $(SRC))
# BONUS_OBJS= $(patsubst $(SRC_B)%.c, $(BIN_BONUS)%.o, $(BONUS))

all: $(NAME)
	echo "Mandatory part OK!🎉"

# bonus: $(NAME_BONUS)
# 	echo "All done for bonus part!🥳"

libft:
	echo "Compiling LIBFT..."
	make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

$(BIN)%.o: $(SRC_D)%.c
	mkdir -p $(BIN)
	$(CC) $(C_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

# $(BIN_BONUS)%.o: $(SRC_B)%.c
# 	mkdir -p $(BIN_BONUS)
# 	$(CC) $(C_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): $(C_OBJS) libft
	echo "Creating $(NAME)"
	$(CC) $(C_OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

# $(NAME_BONUS): $(BONUS_OBJS) libft
# 	echo "Creating $(NAME_BONUS)"
# 	$(CC) $(BONUS_OBJS) $(LIBS) $(INCLUDES) -o $(NAME_BONUS)

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