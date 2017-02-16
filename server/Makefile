SRC	= main.c daemonize.c hygra_daemon.h

OBJ	= main.o \
	  daemonize.o

HEADERS = hygra_daemon.h

CFLAGS += -Wall -Werror -Wextra

NAME = hydra_daemon

all: $(NAME)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all