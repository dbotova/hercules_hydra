/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_accept.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:46:14 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 21:46:15 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int  server_accept_client(t_connection *con)
{
    int c;

    c = 0;
    puts("Waiting for incoming connections...");
    con->client_sock = accept(con->socket_desc, (struct sockaddr *)&con->client, (socklen_t*)&c);
    if (con->client_sock < 0)
    {
        perror("accept failed");
        return (-1);
    }
    puts("Connection accepted");
    return (0);
}
