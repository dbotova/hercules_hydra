#ifndef HYDRA_SERVER_H
# define HYDRA_SERVER_H
# include <sys/resource.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <string.h>
# include "libft.h"
# define BUF_SIZE 2000

typedef struct s_connection
{
	int socket_desc;
	int client_sock;
	char client_message[BUF_SIZE];
	struct sockaddr_in server;
	struct sockaddr_in client;
}				t_connection;

#endif