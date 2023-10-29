//按照学生成绩排序输出
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    Student(){
        _name = "None";
        _score = 0;
    }
    Student(string name,int score){
        _name = name;
        _score = score;
    }
    Student(const Student& s){
        _name = s._name;
        _score = s._score;
    }
    string name(){
        return _name;
    }
    void SetName(string name){
        this->_name = name;
    }
    int score(){
        return _score;
    }
    void SetScore(int score){
        this->_score = score;
    }
    void print(){
        cout << name() <<" " << score()<<endl;
    }
    void operator=(const Student&);
    private:
    string _name;
    int _score;
};
istream& operator>>(istream& cin,Student &s1){
    string name;
    int score;
    cin >> name >> score;
    s1 = Student(name,score);
    return cin;
}
ostream& operator<<(ostream& os,Student &s1){
    s1.print();
    return os;
}
void Student::operator=(const Student& s1){
    SetName(s1._name);
    SetScore(s1._score);
}
void sort(Student* stu){
    for(int i=1;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(stu[j].score() < stu[j+1].score()){
                Student temp;
                temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    }
}
int main(){
    Student stu[5];
    for(int i=0;i<5;i++){
        stu[i] = Student();
    }
    for(int i=0;i<5;i++){
        cin >> stu[i];
    }
    sort(stu);
    cout << " -=====print=====-" <<endl;   
    for(int i=0;i<5;i++){
        cout << stu[i];
    }
}