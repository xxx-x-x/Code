#include<winsock.h>
#include<iostream>
#pragma comment(lib,"ws2_32.lib");

using namespace std;
int main(){
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2,2),&wsadata);
    //socket();
    SOCKET server_sd = socket(AF_INET,SOCK_STREAM,0);
}