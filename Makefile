# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 11:32:20 by amaucher          #+#    #+#              #
#    Updated: 2023/03/22 11:32:23 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binary name
NAME = 
CLIENT =	client
SERVER =	server

# printf library
LIBFTPRINTF_DIR	=	./ft_printf
LIBFTPRINTF	=	$(LIBFTPRINTF_DIR)/libftprintf.a

# client & server variables
SRC_C	=	client.c
SRC_S	=	server.c
OBJ_S	=	server.o
OBJ_C	=	client.o
INC		=	minitalk.h

# compilation & flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
