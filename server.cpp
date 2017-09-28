#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <pthread.h> //for threading , link with lpthread
#include <sstream>
#include <iostream>
#include "list.h"
#include "list.cpp"
#include "cache.h"
#include "cache.cpp"
//the thread function
void *connection_handler(void *);

List<string> list_1;
List1<string> cache;

int main(int argc , char *argv[])
{

    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Socket no creado");
    }
    puts("Socket creado");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8879 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("Error");
        return 1;
    }
    puts("Servicio establecida");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Esperando conexiones entrantes");
    c = sizeof(struct sockaddr_in);


    //Accept and incoming connection
    /*puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);*/

    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Conexión establecida");

        pthread_t sniffer_thread;
        new_sock = (int*) malloc(sizeof *new_sock);
        *new_sock = client_sock;

        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL); // was commented before
    }

    if (client_sock < 0)
    {
        perror("Conexión no establecida");
        return 1;
    }

    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];


    //Receive a message from client

    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //Send the message back to client
        stringstream ss;
        string str;
        ss << client_message;
        ss >> str;
        int pos = str.find(",");
        int acc = str.find("!");
        int acc1 = str.find("#");

        if(acc > 0){
            string key = str.substr(0, pos);
            string value = str.substr(pos+1, (acc-pos-1));

            int exist = list_1.search(key);

            if(exist > 0){
                write(sock , "Elemento existente" , 19);
                bzero(client_message, strlen(client_message));
            }else{
                cache.add_head(value,key);
                list_1.add_head(value,key);
                bzero(client_message, strlen(client_message));
                write(sock , "Elemento creado satisfactoriamente" , 34);

            }
            //list_1.print();
            cache.print();
        }
        if(acc1 > 0){
            string key = str.substr(0, acc1);
            int exist = list_1.search(key);

            if(exist > 0){

                int exist1 = cache.search(key);
                if(exist1 > 0){
                    cache.del_by_data(key);
                    string value = list_1.search1(key);
                    cache.add_head(value ,key);
                }else{
                    string value = list_1.search1(key);
                    cache.add_head(value ,key);;
                }

                char respuesta[1000];
                char div[2];
                strcpy(div, ",");
                char* chr = strdup(key.c_str());
                string value = list_1.search1(key);
                char* chr1 = strdup(value.c_str());
                strcat(respuesta,chr);
                strcat(respuesta,div);
                strcat(respuesta,chr1);
                bzero(client_message, strlen(client_message));
                write(sock , respuesta , 100);

            }else{
                write(sock , "Elemento no existente" , 19);
                bzero(client_message, strlen(client_message));
            }
            //list_1.print();
            cache.print();

        }


    }

    if(read_size == 0)
    {
        puts("Conexión finalizada\n");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);
    close(sock);
    pthread_exit(NULL);
}
