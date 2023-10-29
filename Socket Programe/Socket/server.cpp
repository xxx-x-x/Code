#include<iostream>
#include<winsock.h>
#pragma comment(lib, "ws2_32.lib") 

using namespace std;

int main(){
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2),&wsadata);
    //socket()
    SOCKET server_sd = socket(AF_INET,SOCK_STREAM,0);
    //bind()
    SOCKADDR_IN server_addr;    
    SOCKADDR_IN client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1234);
    bind(server_sd,(SOCKADDR*)&server_addr,sizeof(server_addr));
    //listen()
    listen(server_sd,10);
    //accept()
    int len = sizeof(SOCKADDR);
    SOCKET newSocket = accept(server_sd,(SOCKADDR*)&client_addr,&len);
    //cout 
    cout << "hello" << endl;
    //recv()
    char recv_buf[100];
    recv(newSocket,recv_buf,100,0);
    //cout 
    cout << recv_buf;
    WSACleanup();
    return 0;
}