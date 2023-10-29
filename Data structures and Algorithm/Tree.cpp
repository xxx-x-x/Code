#include<iostream>
#include<stdio.h>
using namespace std;

/*
树有三种存储方法：双亲表示法，孩子表示法，孩子兄弟表示法
我们后面用的二叉树默认都是 二叉排序树，左小右大
二叉树的存储就 数据+左右孩子
*/
class node{
    public:
    int data;
    node * lchild;
    node * rchild;
};

class Tree{
    public:
    Tree(){
        root = creat(root);
    }
    virtual ~Tree(){}
    //要用迭代了,需要传值进入
    //创建树，并且返回根节点
    node* creat(node *p){
        int a;
        cin >> a;
        if(a == -1){
            p=NULL;
        }else{
            p = new node();
            p->data = a;
            p->lchild = creat(p->lchild);
            p->rchild = creat(p->rchild);
        }
        return p;
    }
    void breorder(node *p){
        if(p == nullptr) return ;
        else{
            cout << p->data << " ";
            breorder(p->lchild);
            breorder(p->rchild);
        }
    }
    void inorder(node *p){
        if(p==nullptr)return;
        else{
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }
    node * getRoot(){
        return root;
    }
    private:
    node *root;//存储一个根节点
};

int main(){
    Tree t1;
    t1.inorder(t1.getRoot());
}