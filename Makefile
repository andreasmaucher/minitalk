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

#compilation & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make

#executables
SERVER = server
CLIENT = client

#printf directory / -I searches for header files within that directory
PRINTF = ft_printf/libftprintf.a
INCLUDES = -I ft_printf/includes

all: $(SERVER) $(CLIENT)

$(SERVER): server.c $(PRINTF)
	$(CC) $(CFLAGS) server.c $(PRINTF) $(INCLUDES) -o $(SERVER)

$(CLIENT): client.c $(PRINTF)
	$(CC) $(CFLAGS) client.c $(PRINTF) $(INCLUDES) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C ft_printf clean

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean
	$(MAKE) all