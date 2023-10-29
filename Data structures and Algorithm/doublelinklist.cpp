#include<iostream>
#include<stdio.h>
using namespace std;

class node{
    public:
    int data;
    node* prior;
    node* next;
};

class list{
    public:
    list(){
        head = new node();
        length = 0;
    }
    void creatlist(){
        node * h = head;
        node * p;
        int a;
        while (cin >> a,a!=0)
        {
            p = new node();
            p->data = a;
            p->prior = h;
            h->next = p;
            h = p;
            length ++;
        }
        p->next = head;
    }
    void display(){
        node *h = head->next;
        while (h!=head)
        {
            cout << h->data << " ";
            h = h->next;
        }
        cout << endl;
    }
    void insert(int i,int num){
        node * h = head -> next;
        int j= 1;
        for(;j!=i-1;j++){
            h = h->next;
        }//到这里已经找到要插入位置的前一个节点了
        node * p = new node();
        p->data = num;
        p->prior = h;
        p->next = h->next;
        h->next->prior = p;
        h->next = p;
    }
    void Delete(int i){
        node *p = head->next;
        int j=1;
        while (p!=head)
        {
            if(i==j){
                p->prior->next = p->next;
                p->next ->prior= p->prior;
                delete p;
                return ;
            }
            j++;
            p = p->next;
        }
        
    }
    private:
    node * head;
    int length;
};

int main(){
    list l1;
    l1.creatlist();
    l1.display();
    l1.insert(2,8);
    l1.display();
    l1.Delete(2);
    l1.display();
    return 0;
}