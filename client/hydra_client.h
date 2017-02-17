#ifndef HYDRA_CLIENT_H
# define HYDRA_CLIENT_H
# include <stdio.h>
# include <string.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include "../server/libft.h"
# define BUF_SIZE 1000

typedef struct s_client_connection
{
	int sock;
	struct sockaddr_in server;
}				t_client_connection;

#endif