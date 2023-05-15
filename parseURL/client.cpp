#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
    int clientsd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8070);
    serveraddr.sin_addr.s_addr = inet_addr("43.143.131.87");
    socklen_t st = sizeof(serveraddr);
    int ClientSocket = connect(clientsd,(sockaddr*)&serveraddr,st);
    if(ClientSocket != -1)
    {
        std::cout << "connect success" << std::endl;
    }
        int buffer = 1234;
    send(ClientSocket,&buffer,sizeof(int),0);
    return 0;
}
