#include "hydra_server.h"

static int init_connnect(t_connection *con)
{
    con->socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (con->socket_desc == -1)
    {
        puts("Could not create socket");
        return (-1);
    }
    puts("Socket created");

    con->server.sin_family = AF_INET;
    con->server.sin_addr.s_addr = INADDR_ANY;
    con->server.sin_port = htons(8888);
    if(bind(con->socket_desc, (struct sockaddr *)&con->server, sizeof(con->server)) < 0)
    {
        perror("bind failed. Error");
        return (-1);
    }
    puts("bind done");
    return (0);
}

static int hydra_connect(t_connection *con)
{
    int c;

    if (init_connnect(con) < 0)
    {
        perror("Error occured");
        return (-1);
    }
    listen(con->socket_desc , 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    con->client_sock = accept(con->socket_desc, (struct sockaddr *)&con->client, (socklen_t*)&c);
    if (con->client_sock < 0)
    {
        perror("accept failed");
        return (-1);
    }
    puts("Connection accepted");
    return (0);
}

int main(int argc, char **argv)
{
    t_connection *con;
    int read_size;

    con = malloc(sizeof(t_connection));
    hydra_connect(con);
    if (con->client_sock < 1)
        return (1);
    while((read_size = recv(con->client_sock, con->client_message, BUF_SIZE , 0)) > 0)
    {
        if (ft_strcmp(con->client_message, "ping") == 0)
            write(con->client_sock , "pong pong\n", ft_strlen("pong pong\n"));
        if ((ft_strcmp(con->client_message, "stop") == 0))
        {
            puts("Server has been stopped");
            SMART_FREE(con);
            exit(0);
        }
        else
            write(con->client_sock, con->client_message, ft_strlen(con->client_message));
    }
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
        perror("recv failed");
    SMART_FREE(con);
    return (0);
}