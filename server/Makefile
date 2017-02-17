# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 20:17:34 by dbotova           #+#    #+#              #
#    Updated: 2017/02/16 20:17:37 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = hydra_server.o server_listen.o server_init.o daemon_listen.o 		\
	   server_connect.o server_accept.o
LIBS = libft.a

HEADERS = hydra_server.h libft.h

CFLAGS += -Wall -Werror -Wextra

NAME = hydra_server

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
