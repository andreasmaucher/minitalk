/*2 programs 
include printf in subdirectory
makefile is not allowed to relink, meaning if I did make once and o files
 and executables got generated
I am not allowed to do this again before I do clean */

SRCS = client.c server.c utils.c \

OBJS = $(SRCS:.c=.o)

# compilation & flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = 
CLIENT =	client
SERVER =	server

# printf library

//!


all: $(SERVER) $(CLIENT)

$(NAME): all


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all