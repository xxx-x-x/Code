#include<stdio.h>
#include<iostream>
using namespace std;

template<typename elemType>
class example{
    public:
    example(elemType min,elemType max);
    example(const elemType * array, int size);
    elemType& operator[] (int index);
    bool operator == (const example&)const;
    bool insert(const elemType*,int);
    bool insert(const elemType&);
    elemType min() const {return _min;};
    elemType max() const {return _max;};
    void min(const elemType&);
    void max(const elemType&);
    int count(double value) const;
    private:
    int size;
    elemType *parray;
    elemType _min;
    elemType _max;
};

int main(){
    return 0;
}