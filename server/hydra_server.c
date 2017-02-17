/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:17:50 by dbotova           #+#    #+#             */
/*   Updated: 2017/02/16 20:17:53 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hydra_server.h"

int main(int argc, char **argv)
{
    t_connection *con;
    int is_d;

    is_d = 0;
    con = NULL;
    if (argc == 2 && ft_strcmp(argv[1], "-D") == 0)
        is_d = 1;
    hydra_connect(con, is_d);
    if (con->client_sock < 1)
        return (1);
    SMART_FREE(con);
    return (0);
}
