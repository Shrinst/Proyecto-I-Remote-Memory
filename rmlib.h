#include <stdio.h> //printf
#include <string.h>    //strlen
#include <stdlib.h>
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h> // close socket
#include <string>
#include <sstream>
#include <iostream>
#include "rmRef_H.h"

int sock;
struct sockaddr_in server;
char server_reply[1000];

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
    }

}
void rm_new (char *key, void *value, int value_size){

    char message[1000];
    char message1[1000];
    char separador[1000];
    char accion[1000];
    char accion1[1000];
    strcpy(message, key);
    strcpy(message1, (char *)value);
    strcpy(separador, ",");
    strcpy(accion1, "!");
    strncat (message, separador, strlen(separador));
    strncat (message, message1, strlen(message1));
    strncat (message, accion1, strlen(accion1));

    if( send(sock , message , strlen(message) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }

    puts(server_reply);
    //close(sock);
}
void rm_get1(char* key){

    char message[1000];
    char accion[1000];
    strcpy(message, key);
    strcpy(accion, "#");
    strncat (message, accion, strlen(accion));

    if( send(sock , message , strlen(message) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }

    puts(server_reply);
}
char* rm_getM(char* key){

    char message[1000];
    char accion[1000];
    strcpy(message, key);
    strcpy(accion, "!");
    strncat (message, accion, strlen(accion));

    if( send(sock , message , strlen(message) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }

    return server_reply;
}
int rm_getCN(){
    char accion[1000];
    strcpy(accion, "$");

    if( send(sock , accion , strlen(accion) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    int sum = atoi( server_reply );
    return sum;
}
int rm_getMN(){
    char accion[1000];
    strcpy(accion, "&");

    if( send(sock , accion , strlen(accion) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    int sum = atoi( server_reply );
    return sum;
}
std::string rm_getCK(int num){
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    char* cant = strdup(str.c_str());
    char accion[1000];
    strcpy(accion, "¡");
    strncat (cant, accion, strlen(accion));

    if( send(sock , cant , strlen(cant) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    std::stringstream ss1;
    std::string str1;
    ss1 << server_reply;
    ss1 >> str1;
    return str1;
}
std::string rm_getCV(int num){
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    char* cant = strdup(str.c_str());
    char accion[1000];
    strcpy(accion, "?");
    strncat (cant, accion, strlen(accion));

    if( send(sock , cant , strlen(cant) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    std::stringstream ss1;
    std::string str1;
    ss1 << server_reply;
    ss1 >> str1;
    return str1;
}
std::string rm_getMK(int num){
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    char* cant = strdup(str.c_str());
    char accion[1000];
    strcpy(accion, "=");
    strncat (cant, accion, strlen(accion));

    if( send(sock , cant , strlen(cant) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    std::stringstream ss1;
    std::string str1;
    ss1 << server_reply;
    ss1 >> str1;
    return str1;
}
std::string rm_getMV(int num){
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    char* cant = strdup(str.c_str());
    char accion[1000];
    strcpy(accion, ")");
    strncat (cant, accion, strlen(accion));

    if( send(sock , cant , strlen(cant) , 0) < 0){

        puts("Falló el envio");
    }

    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
    std::stringstream ss1;
    std::string str1;
    ss1 << server_reply;
    ss1 >> str1;
    return str1;
}
void rm_delete(rmRef_H* handler){

    char message[1000];
    char message1[1000];
    char separador[1000];
    char accion[1000];
    strcpy(accion, "/");
    strcpy(separador, ",");
    strcpy(message, (char *)handler->key);
    strcpy(message1, (char *)handler->data);
    strncat (message, separador, strlen(separador));
    strncat (message, message1, strlen(message1));
    strncat (message, accion, strlen(accion));
    puts(message);
    if( send(sock , message , strlen(message) , 0) < 0){
        puts("Falló el envio");
    }
    if( recv(sock , server_reply , 2000 , 0) < 0){

        puts("recv failed");
    }
}
