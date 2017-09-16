#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <unistd.h> // close socket

int sock;
struct sockaddr_in server;
char message[1000] , server_reply[1000];

void rm_init (int ip, int port, int ipHA, int portHA){
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket creado");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("Falló la conección");
    }else{
        puts("Conexión establecida\n");

        //keep communicating with server
        printf( "Type 'e' to end the session:\n");
    }

}
void rm_new (char *key, void *value, int value_size){

    char* valor = (char*) value;
    if( valor[0] == 'e')
        {
             close(sock);
        }

        else{

            //Send some data
            if( send(sock , valor , strlen(valor) , 0) < 0)
            {
                puts("Send failed");
            }
        }

    close(sock);
}
