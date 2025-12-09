# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 16:14:46 by afournie          #+#    #+#              #
#    Updated: 2025/12/01 10:38:12 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar rcs
RM				=	rm -rf

SRC				=	ft_printf ft_putnbr ft_putstr ft_putnbr_hexa
SRCS 			=	$(addsuffix .c, $(SRC))

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)


$(NAME):			$(OBJ_DIR) $(OBJS)
					$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re
