/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_connect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:11:46 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 21:11:51 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int hydra_connect(t_connection *con, int is_d)
{
    pid_t pid;

    con = malloc(sizeof(t_connection));
    if (init_connnect(con) < 0)
    {
        perror("Error occured");
        exit(-1);
    }
    listen(con->socket_desc , 3);
    if (is_d)
    {
        if ((pid = fork()) < 0)
            exit(-1);
        if (pid == 0)
            exit(daemon_listen(con));
        else
            exit(0);
    }
    else if (hydra_listen(con) < 0)
        return (-1);
    return (0);
}
