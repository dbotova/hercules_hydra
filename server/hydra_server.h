/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_server.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:18:00 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 20:18:02 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/wait.h>
# include <signal.h>
# define BUF_SIZE 2000

typedef struct	s_connection
{
	int			socket_desc;
	int			client_sock;
	char		client_message[BUF_SIZE];
	struct		sockaddr_in server;
	struct		sockaddr_in client;
}				t_connection;

int 			hydra_listen(t_connection *con);
int				init_connnect(t_connection *con);
int 			daemon_listen(t_connection *con);
int				hydra_connect(t_connection *con, int is_d);
int  			server_accept_client(t_connection *con);

#endif
