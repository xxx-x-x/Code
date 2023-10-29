#include<iostream>
#include<winsock.h>
using namespace std;

int main(){
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2),&wsadata);
    //socket()
    SOCKET client_sd = socket(AF_INET,SOCK_STREAM,0);
    //connect()
    SOCKADDR_IN server_addr;
    server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(1234);
    server_addr.sin_family = AF_INET;
    connect(client_sd,(SOCKADDR*)&server_addr,sizeof(SOCKADDR));
    //send()
    char send_buf[100];
    cin >> send_buf;
    send(client_sd,send_buf,100,0);
    WSACleanup();
    return 0;
}