#include<stdio.h>
#include<openssl/md5.h>
#include<string>
#include<string.h>
#include<iostream>


using namespace std;
string MD5(string src){
    unsigned char   md[16] = {0};
    char tmp[16] = {0};
    string result;
    MD5_CTX ctx; 
    MD5_Init(&ctx);
    MD5_Update(&ctx,src.c_str(),src.size());
    MD5_Final(md,&ctx);

    for(int i=0;i<16;i++){
        memset(tmp,0x00,sizeof(tmp));
        snprintf(tmp,sizeof(tmp),"%02X",md[i]);
        result += tmp;
    }
    return result;
}
int main(int argc,char* argv[])
{
    string src = argv[1];
    string result = MD5(src);
    std::cout << result << std::endl;
    return 0;
}
