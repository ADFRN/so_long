# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 10:47:00 by afournie          #+#    #+#              #
#    Updated: 2025/12/15 16:02:53 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          = so_long
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -g

LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

PRINTF_DIR    = printf
PRINTF        = $(PRINTF_DIR)/libftprintf.a

MINILIBX_DIR  = minilibx/minilibx-linux
MINILIBX      = $(MINILIBX_DIR)/libmlx_Linux.a

INC           = -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MINILIBX_DIR)

SRCS_DIR      = srcs

SRCS          = $(SRCS_DIR)/map_verificator.c \
				$(SRCS_DIR)/get_next_line.c \
				$(SRCS_DIR)/get_map_info.c \
				$(SRCS_DIR)/movements.c \
				$(SRCS_DIR)/free_all.c \
				$(SRCS_DIR)/graphics.c \
				$(SRCS_DIR)/events.c \
				$(SRCS_DIR)/main.c

OBJS         = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) -L.. -Lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "✅ $(NAME) generated"

$(LIBFT):
	@echo "📚 Compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "✅ libft generated"

$(PRINTF):
	@echo "📚 Compiling printf..."
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "✅ printf generated"

$(MINILIBX):
	@echo "📚 Compiling minilibx..."
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "✅ minilibx generated"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "🧹 Cleaning objects..."
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "✅ Objects cleaned"

fclean: clean
	@echo "🗑️  Full clean..."
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "✅ $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
