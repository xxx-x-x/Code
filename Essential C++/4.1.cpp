#include "4.1.h"

inline bool Stack::empty(){
    return _stack.empty();
}

bool Stack::pop(string &elem){
    if(empty()){
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}
inline bool Stack::full(){
    return _stack.size() == _stack.max_size();
}
bool Stack::peek(string &elem){
    if(empty()){
        return false;
    }
    elem = _stack.back();
    return true;
}
bool Stack::push(const string &elem){
    if(full()){
        return false;
    }
    _stack.push_back(elem);
    return true;
}
bool Stack::find(const string & elem){
    if(empty()){
        return false;
    }
    vector<string>::iterator it = _stack.begin();
    for(;it!=_stack.end();it++){
        if(*it == elem){
            return true;
        }
    }
    return false;
}

int Stack::count(const string& elem){
    int num = 0;
    if(empty()){
        return 0;
    }
    vector<string>::iterator it = _stack.begin();
    for(;it!=_stack.end();it++){
        if(*it == elem){
            num++;
        }
    }
    return num;
}
int main(){
    Stack st1;
    st1.push("one");
    string str = "one";
    cout << st1.count("one") << endl;
    return 0;
}