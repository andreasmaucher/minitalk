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

F_SERVER = server.c
F_CLIENT = client.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
PRINTF = ft_printf/libftprintf.a
INCLUDES = -I ft_printf/includes
MAKE = make

all: $(SERVER) $(CLIENT)

$(SERVER): $(F_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) $(F_SERVER) $(PRINTF) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(F_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) $(F_CLIENT) $(PRINTF) $(INCLUDES) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C ft_printf clean

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean
	$(MAKE) all
