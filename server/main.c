#include "hydra_daemon.h"

static int hydra_connect(int socket_desc, struct sockaddr_in server, struct sockaddr_in client)
{
    int c;
    int client_sock;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
        puts("Could not create socket");
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
     
    //Bind
    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("bind failed. Error");
        return (-1);
    }
    puts("bind done");
    listen(socket_desc , 3);
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return (-1);
    }
    puts("Connection accepted");
    return (client_sock);
}

static int read_client(int cl_sock, int socket_desc, struct sockaddr_in server, struct sockaddr_in client)
{
     char client_message[BUF_SIZE];
     int read_size;
     int client_sock;

     client_sock = cl_sock;

    while((read_size = recv(client_sock , client_message , BUF_SIZE , 0)) > 0)
    {
        if (strcmp(client_message, "ping") == 0)
            write(client_sock , "pong pong\n", strlen("pong pong\n"));
        if ((strcmp(client_message, "stop") == 0))
        {
            fflush(stdout);
            return (0);
        }
        if ((strcmp(client_message, "restart") == 0))
        {
            fflush(stdout);
            client_sock = hydra_connect(socket_desc, server, client);
        }
        else
            write(client_sock , client_message , strlen(client_message));
    }
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
        perror("recv failed");
    return (0);
}

int main(int argc, char **argv)
{
	int socket_desc , client_sock; 
    //int read_size;
    struct sockaddr_in server , client;
    //char client_message[BUF_SIZE];

    client_sock = hydra_connect(socket_desc, server, client);
    if (client_sock < 1)
    {
        perror("error");
        return (1);
    }
    read_client(client_sock, socket_desc, server, client);
    // while((read_size = recv(client_sock , client_message , BUF_SIZE , 0)) > 0)
    // {
    //     if (strcmp(client_message, "ping") == 0)
    //         write(client_sock , "pong pong\n", strlen("pong pong\n"));
    //     if ((strcmp(client_message, "stop") == 0))
    //     {
    //         fflush(stdout);
    //         exit(0);
    //     }
    //     if ((strcmp(client_message, "restart") == 0))
    //     {
    //         fflush(stdout);
    //         client_sock = hydra_connect(socket_desc, server, client);
    //     }
    //     else
    //         write(client_sock , client_message , strlen(client_message));
    // }
     
    // if(read_size == 0)
    // {
    //     puts("Client disconnected");
    //     fflush(stdout);
    // }
    // else if(read_size == -1)
    //     perror("recv failed");
     
    return (0);
}