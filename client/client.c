#include "hydra_client.h"

static int init_connect(t_client_connection *con)
{
    con->sock = socket(AF_INET , SOCK_STREAM , 0);
    if (con->sock == -1)
    {
        puts("Could not create socket");
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
        puts("Enter message : ");
        get_next_line(0, &message);

        if (strcmp(message, "exit") == 0)
            break ;

        if(send(con->sock, message, ft_strlen(message), 0) < 0)
        {
            printf("Send failed");
            return (-1);
        }
        if(recv(con->sock, server_reply, BUF_SIZE * 2, 0) < 0)
        {
            puts("recv failed");
            return (-1);
        }
        puts("Server reply :");
        puts(server_reply);
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
    puts("Connected");
    read_server(con);
    close(con->sock);
    SMART_FREE(con);
    return (0);
}