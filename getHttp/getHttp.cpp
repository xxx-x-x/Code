#include<stdio.h>
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string> 

using namespace std;

string Header[120];
int clientfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
struct sockaddr_in serveraddr;

void ParseURL(string& Protocol,string& Domain,string& Port,string& Path,string& User,string& Password){
    int Lpro,Lpath;
    string url = "http://43.143.131.87:8070/microsoft.txt";
    
    Lpro = url.find("//");
    Protocol = url.substr(0,Lpro-1);
    string resPath = url.substr(Lpro+2);

    Lpath = resPath.find("/");
    Path = resPath.substr(Lpath);
    string resDomain;
    resDomain = url.substr(Lpro+2,Lpath);
    if(resDomain.find('@')!= -1){
        string tmpDomain = resDomain.substr(resDomain.find('@')+1);
        int temp = resDomain.substr(0,resDomain.find('@')).find(':');
        User = resDomain.substr(0,resDomain.find('@')).substr(0,temp);
        Password = resDomain.substr(0,resDomain.find('@')).substr(temp+1);
        Domain = tmpDomain.substr(0,tmpDomain.find(':'));
        Port = tmpDomain.substr(tmpDomain.find(':')+1);
    }else{
        Domain = resDomain.substr(0,resDomain.find(':'));
        Port = resDomain.substr(resDomain.find(':')+1);
        User = "";
        Password = "";
    }
    cout << "Protocol:" << Protocol << endl;
    cout << "User:" << User << endl;
    cout << "Password:" << Password << endl;
    cout << "Domain:" << Domain << endl;
    cout << "Port:" << Port << endl;
    cout << "Path:" << Path << endl << endl << endl;
}

void Net(string& Domain,string& Port){
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(stoi(Port));
    serveraddr.sin_addr.s_addr = inet_addr(Domain.c_str());
    connect(clientfd,(sockaddr*)&serveraddr,sizeof(serveraddr));
}

void CreateHeader(string& Domain,string& Path,string& Port){
   Header[0] = "GET "+Path+" HTTP/1.1\\r\\n"; 
   Header[1] = "Connection: close\\r\\n";
   //Header[2] = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\r\n";
   //Header[3] = "Accept-Encoding: gzip, deflate\r\n";
   //Header[4] = "Accept-Language: zh-CN,zh;q=0.9\r\n";
   //Header[5] = "Cache_Control: max-age=0\r\n";
   //Header[6] = "Host: "+Domain+":"+Port+"\r\n";
   //Header[7] = "Referer: http://43.143.131.87:8080/\r\n";
   //Header[8] = "Upgrade-Insecure-Requests: 1\r\n";
   //Header[9] = "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36\r\n";
   Header[10] = "\r\n";

   for(int i=0;i<11;i++){
    cout << Header[i];
   }
}
int main(){
    string Protocol,Domain,Path,User,Password,Port;
    ParseURL(Protocol,Domain,Port,Path,User,Password);
    Net(Domain,Port);
    CreateHeader(Domain,Path,Port);
    send(clientfd,Header,120,0);
    char html[1024*5];
    int RecvNum = recv(clientfd,html,1024*5,0);
    cout << RecvNum << endl;
    if(RecvNum<0){
        cout << "recv failed!" << endl;
    }else{
        cout << html << endl;
    }

    return 0;
}