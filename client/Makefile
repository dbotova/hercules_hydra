# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 20:18:29 by dbotova           #+#    #+#              #
#    Updated: 2017/02/16 20:18:30 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = client.o
LIBS = ../server/libft.a

HEADERS = hydra_client.h ../server/libft.h

CFLAGS += -Wall -Werror -Wextra

NAME = hydra_client

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ): $(HEADERS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
