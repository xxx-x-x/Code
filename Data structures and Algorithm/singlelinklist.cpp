//循环链表就是单链表，只是最后一个节点的next不再是空，而是指向了头节点。
#include<iostream>
#include<stdio.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
};

class nodelist{
    public:
    nodelist(){
        head = new node();
        head->next = nullptr;
        length = 0;
    }
    virtual~nodelist(){
        node *pre,*p;
        pre = head;
        p = pre->next;
        while (p != nullptr)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    void creatnodelist(){
        //需要两个指针，一个指针指向当前，一个指针指向新创建
        node *p,*t;
        int a;
        p = head;//空的时候，P应该指向的是头指针
        while (cin>>a,a!=0)
        {
            t = new node();
            t->data = a;
            p->next = t;
            p = t;
            length ++;
        }
        p->next = nullptr;
        
    }
    void displaylist(){
        node* p = head->next;
        while (p!= nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl; 
    }
    int rlength(){
        return length;
    }
    bool isEmpty(){
        if(length!=0){
            cout << "list is not empty" << endl;
            return false;
        }else{
            cout << "list is empty" << endl;
            return true;
        }
    }
    //根据位置查找
    int getElemByindex(int i){
        if(i>length || i<=0){
            cerr << "数组下标越界" << endl;
            return -1;
        }
        node*p;
        p = head ->next;
        int j=0;
        while (j!=i-1)
        {
            p = p->next;
            j++;
        }
        cout << "查找的数为" << p->data << endl;
    }
    //查找元素
    int getIndexByElem(int a){
        node * p;
        p = head->next;
        int i = 0;
        while (p!=nullptr)
        {
            if(p->data != a){
                p = p->next;
                i++;
            }else{
                return i+1;
            }
        }
        cerr << " 没有找到" << endl;
        
    }
    //在第几个位置插入元素，返回值为是否成功    
    bool insert(int i,int num){
        node *p,*s;
        int j=1;
        p = head;
        while(p!=nullptr){
            if(i == j){
                s = new node();
                s->data = num;
                s->next = p->next;
                p->next = s;
                return true;
            }
            j++;
            p = p->next;
        }
        return false;
    }
    bool Delete(int i){
        node* p;
        p = head;
        int j=0;
        while (p!=nullptr)
        {
            if(j==i-1){
                p->next = p->next->next;
                return true;
            }
            j++;
            p = p->next;
        }
        return false;
        
    }
    private:
    node* head;
    int length;
};

int main(){
    nodelist n1;
    n1.creatnodelist();
    n1.displaylist();
    if(n1.insert(2,3)){
        cout << "成功了插入了" <<endl;
    }
    n1.displaylist();
    if(n1.Delete(2)){
        cout << "成功删除了" << endl;
    }
    n1.displaylist();
    return 0;
}