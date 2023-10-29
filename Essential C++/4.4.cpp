#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;

class UserProfile{
public:
    //枚举类
    enum ulevel {Beginner,Intermediate,Advanced,Guru};
    //构造函数
    UserProfile(string login,ulevel = Beginner);
    UserProfile();
    //重载运算符
    bool operator==(const UserProfile&);
    bool operator!=(const UserProfile& rhs);
    // 以下函数用来读取数据
    //1，取数据
    string login() const {return _login;}
    string user_name() const{return _user_name;}
    int login_count() const{return _times_logged;}
    int guess_count() const{return _guesses;}
    int guess_correct() const {return _correct_guesses;}
    //2,返回计算的数据
    double guess_average() const;
    string level() const;
    //以下函数用来写数据
    void reset_login(const string& str){_login = str;}
    void reset_user_name(const string& str){_user_name = str;}
    void reset_login_count(int val){_times_logged = val;}
    void reset_guess_count(int val){_guesses = val;}
    void reset_guess_correct(int val){_correct_guesses = val;}

    void reset_level(const string&);
    void reset_level(ulevel newlevel){_uesr_level = newlevel;}

    void bump_login_count(int cnt = 1){ _times_logged += cnt;}
    void bump_guess_count(int cnt = 1){_guesses += cnt;}
    void bump_guess_correct(int cnt =1){_correct_guesses += cnt;}
private:
    string _login;
    string _user_name;
    int _times_logged;
    int _guesses;
    int _correct_guesses;
    ulevel _uesr_level;

    static map<string,ulevel> _level_map;
    static void init_level_map();
    static string guest_login();
};
inline double UserProfile::guess_average() const{
    return _guesses ? double(_correct_guesses)/double(_guesses) * 100 : 0.0;
}
inline UserProfile::UserProfile(string login,ulevel level){
    _login = login;
    _uesr_level = level;
    _times_logged = 1;
    _guesses = 0;
    _correct_guesses = 0;
}
inline UserProfile::UserProfile(){
    _login = "guest";
    _uesr_level = Beginner;
    _times_logged = 1;
    _guesses = 0;
    _correct_guesses = 0;
    static int id = 0;
    char buffer[16];
    //给一个整数，变成ascii
    //第一个参数要被转换的数，第二个是要存放的数组名，第三个是进制
    _itoa(id++,buffer,10);
    _login += buffer;
    //所谓的会话标识符session id 就是 在名字后面加了个文字，然后
}
inline bool UserProfile::operator==(const UserProfile& rhs){
    if(_login == rhs._login && _user_name == rhs._user_name){
        return true;
    }
    return false;
}
inline bool UserProfile::operator!=(const UserProfile& rhs){
    return !(*this == rhs);
}

ostream& operator<< (ostream& os,const UserProfile& UP){
    os << UP.login() << ' ' << UP.level() << ' ' << UP.login_count() << ' ' << UP.guess_count()<<' '<<UP.guess_correct() <<' ' << UP.guess_average() << endl;
    return os;
}

//这里是在全局定义的，所以下面函数里能调用
map<string,UserProfile::ulevel> UserProfile::_level_map;
void UserProfile:: init_level_map(){
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}
inline void UserProfile::reset_level(const string & level){
    map<string,ulevel>::iterator it;
    if(_level_map.empty()){
        init_level_map();
    }
    _uesr_level = ((it = _level_map.find(level))!= _level_map.end()) ? it->second : Beginner;
}

istream& operator >>(istream& is,UserProfile &rhs){
    string login,level;
    is >> login >> level;
    int lcount,gcount,gcorrect;
    is >> lcount >> gcount>>gcorrect;
    rhs.reset_login(login);
    rhs.reset_level(level);
    rhs.reset_login_count(lcount);
    rhs.reset_guess_count(gcount);
    rhs.reset_guess_correct(gcorrect);
    return is;
}

int main(){
    UserProfile anon;
    cout << anon;shaizi
}