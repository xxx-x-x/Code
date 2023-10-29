#include<iostream>
#include<Vector>
#include<string.h>
using namespace std;
void Vec();
void Arr();

int main(){
    Arr();
}

void Vec(){
    int num;
    vector<int> v1;
    int sum = 0;
    int ave;
    while (cin >> num )
    {
        v1.push_back(num);
    }
    for(int i=0;i<v1.size();i++){
        sum += v1[i];
    }
    ave = sum/v1.size();
    cout << sum << " "<<ave;
}

void Arr(){
    int num;
    int number;
    int array_size = 1024;
    int arr[array_size];
    int sum =0;
    int ave;
    //判断，如果输入的话，总数加1，并且赋值
    while (cin >> num && number < array_size)
    {
        arr[number++] = num;
    }
    for(int i=0;i<number;i++){
        sum += arr[i];
    }
    ave = sum / number;
    cout << "sum" << sum <<"ave"<<ave << endl;
}