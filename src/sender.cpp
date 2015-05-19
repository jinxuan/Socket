//
// Created by jinxuan wu on 5/19/15.
//

#include "sender.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    if(argc <= 2) {
        printf("usage: %s ip_address port_number\n", argv[0]);
        return 1;
    }

    const char* ip = argv[1];
    int port=atoi(argv[2]);
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip,  &server_address.sin_addr);
    server_address.sin_port = htons(port);


    return 0;
}