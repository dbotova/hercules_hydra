/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_listen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:21:42 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 20:21:43 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int hydra_listen(t_connection *con)
{
    int c;

    c = 0;
    int read_size;

    c = sizeof(struct sockaddr_in);
    if (server_accept_client(con) < 0)
        exit(-1);
    while((read_size = recv(con->client_sock, con->client_message, BUF_SIZE , 0)) >= 0)
    {
        if (read_size > 0)
            write(con->client_sock , "pong\npong", ft_strlen("pong\npong"));
        else
        {
            puts("Client disconnected");
            fflush(stdout);
            if (server_accept_client(con) < 0)
                exit(-1);
        }
    }
    if(read_size == -1)
        perror("recv failed");
    exit(0);
}
