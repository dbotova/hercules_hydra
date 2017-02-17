/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:18:43 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 20:18:44 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_client.h"

static int init_connect(t_client_connection *con)
{
    con->sock = socket(AF_INET , SOCK_STREAM , 0);
    if (con->sock == -1)
    {
        ft_printf("Could not create socket\n");
        return (-1);
    }
    puts("Socket created");
    con->server.sin_addr.s_addr = inet_addr("127.0.0.1");
    con->server.sin_family = AF_INET;
    con->server.sin_port = htons(8888);
    if (connect(con->sock, (struct sockaddr *)&con->server, sizeof(con->server)) < 0)
    {
        perror("connect failed. Error");
        return (-1);
    }
    return (0);
}

static int read_server(t_client_connection *con)
{
    char *message;
    char server_reply[BUF_SIZE * 2] = {0};
     
    message = NULL;
    while(42)
    {
        ft_printf("\nEnter message :\n");
        get_next_line(0, &message);
        if (ft_strcmp(message, "exit") == 0)
            break ;
        if(send(con->sock, message, ft_strlen(message), 0) < 0)
        {
            perror("Send failed");
            return (-1);
        }
        if(recv(con->sock, server_reply, BUF_SIZE * 2, 0) < 0)
        {
            perror("recv failed");
            return (-1);
        }
        ft_printf("\nServer reply :\n");
        ft_printf("%s", server_reply);
        SMART_FREE(message);
    }
    return (0);
}

int main()
{
    t_client_connection *con;

    con = malloc(sizeof(t_client_connection));
    if (init_connect(con) < 0)
        return (-1);
    ft_printf("Connected\n");
    read_server(con);
    close(con->sock);
    SMART_FREE(con);
    return (0);
}
