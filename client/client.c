#include "hydra_client.h"

int main(int argc , char **argv)
{
    int sock;
    struct sockaddr_in server;
    char message[BUF_SIZE] , server_reply[BUF_SIZE * 2];
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
        printf("Could not create socket");
    printf("Socket created");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
 
    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
     
    printf("Connected\n");
     
    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);
         
        //Send some data
        if (strcmp(message, "exit") == 0)
            break ;
        if(send(sock , message , strlen(message) , 0) < 0)
        {
            printf("Send failed");
            return 1;
        }
        if(recv(sock , server_reply , BUF_SIZE * 2 , 0) < 0)
        {
            printf("recv failed");
            break ;
        }
         
        ppintf("Server reply :");
        printf(server_reply);
    }
     
    close(sock);
    return 0;
}