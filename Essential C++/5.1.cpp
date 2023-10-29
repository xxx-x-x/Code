#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 抽象类，纯虚函数导致无法实例化对象
class Stack{
    public:
    Stack(){};
    ~Stack(){};
    virtual bool pop(string&)=0;
    virtual bool push(const string&)=0;
    virtual bool peek(int index,string&)=0;

    virtual int top() const=0;
    virtual int size() const=0;

    virtual bool empty() const=0;
    virtual bool full() const=0;
    virtual void print(ostream& = cout) const=0;
};

ostream& operator<<(ostream& os,Stack& rhs){
    rhs.print();
    return os;
}

class LIFO_Stack : public Stack{
public:
    LIFO_Stack(int capacity = 0){
        _top = 0;
        if(capacity){
            _stack.reserve(capacity);
        }
    }
    int size() const {
        return _stack.size();
    }
    bool empty() const{
        return !_top;
    }
    bool full() const {
        return size()>= _stack.max_size();
    }
    int top() const{
        return _top;
    }
    void print(ostream& os = cout)const;
    bool pop(string& elem);
    bool push(const string& elem);
    bool peek(int ,string& elem){
        return true;
    }
private:
    vector<string> _stack;
    int _top;
};

bool LIFO_Stack::pop(string& elem){
    if(empty())return false;
    elem = _stack[--_top];
    _stack.pop_back();
    return true;
}
bool LIFO_Stack::push(const string& elem){
    if(full())return false;
    _stack.push_back(elem);
    _top++;
    return true;
}
void LIFO_Stack::print(ostream& os)const{
    vector<string>::const_reverse_iterator rit = _stack.rbegin();
    vector<string>::const_reverse_iterator rend = _stack.rend();
    os << "\n\t";
    while (rit!= rend)
    {
        os << *rit++ << "\n\t";
    }
    os << endl;
    
}
int main(){
    LIFO_Stack ls;
    string str;
    while (cin >> str && !ls.full())
    {
        ls.push(str);
    }
    cout << " peek() " << endl;
    return 0;
}