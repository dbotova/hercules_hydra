#include "hydra_daemon.h"

static int hydra_connect(t_connection *con)
{
    int c;
    //int client_sock;

    con->socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (con->socket_desc == -1)
        puts("Could not create socket");
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    con->server.sin_family = AF_INET;
    con->server.sin_addr.s_addr = INADDR_ANY;
    con->server.sin_port = htons(8888);
     
    //Bind
    if(bind(con->socket_desc,(struct sockaddr *)&con->server , sizeof(con->server)) < 0)
    {
        perror("bind failed. Error");
        return (-1);
    }
    puts("bind done");
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
    //return (client_sock);
}

int main(int argc, char **argv)
{
    t_connection *con;

    con = malloc(sizeof(t_connection));
	// int socket_desc , client_sock; 
    int read_size;
 //    struct sockaddr_in server , client;
 //    //char client_message[BUF_SIZE];

    hydra_connect(con);
    //client_sock = hydra_connect(socket_desc, server, client);
    if (con->client_sock < 1)
    {
        perror("error");
        return (1);
    }
    while((read_size = recv(con->client_sock , con->client_message , BUF_SIZE , 0)) > 0)
    {
        if (strcmp(con->client_message, "ping") == 0)
            write(con->client_sock , "pong pong\n", strlen("pong pong\n"));
        if ((strcmp(con->client_message, "stop") == 0))
        {
            fflush(stdout);
            exit(0);
        }
        if ((strcmp(con->client_message, "restart") == 0))
        {
            fflush(stdout);
            //client_sock = hydra_connect(socket_desc, server, client);
            hydra_connect(con);
        }
        else
            write(con->client_sock , con->client_message , strlen(con->client_message));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
        perror("recv failed");
    free(con);
    con = NULL;
    return (0);
}