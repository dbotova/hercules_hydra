/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon_listen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:50:18 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 20:50:20 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

static int  daemon_accept_client(t_connection *con)
{
    int c;

    c = 0;
    con->client_sock = accept(con->socket_desc, (struct sockaddr *)&con->client,
        (socklen_t*)&c);
    if (con->client_sock < 0)
    {
        perror("accept failed");
        return (-1);
    }
    return (0);
}

int daemon_listen(t_connection *con)
{
    int c;

    c = 0;
    int read_size;

    c = sizeof(struct sockaddr_in);
    if (daemon_accept_client(con) < 0)
        exit(-1);
    while((read_size = recv(con->client_sock, con->client_message, BUF_SIZE , 0)) >= 0)
    {
        if (read_size > 0)
            write(con->client_sock , "pong\npong", ft_strlen("pong\npong"));
        else
        {
            fflush(stdout);
            if (daemon_accept_client(con) < 0)
                exit(-1);
        }
    }
    if(read_size == -1)
    {
        perror("recv failed");
        exit(-1);
    }
    SMART_FREE(con);
    exit(0);
}
