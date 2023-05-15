#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
    int serversd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    serveraddr.sin_port = htons(8070);
    bind(serversd,(sockaddr*)&serveraddr,sizeof(serveraddr));
    if(listen(serversd,10)!=0){
        printf("listen failed");
        return -1;
    };  
    struct sockaddr_in clientaddr;
    socklen_t st = sizeof(clientaddr);
    int clientsd = accept(serversd,(struct sockaddr*)&clientaddr,&st); 
    std::cout << clientsd << std::endl;
    int buffer;
    recv(clientsd,&buffer,sizeof(int),0);
    std::cout << buffer<< std::endl;
    return 0;
}