#include<stdio.h>
#include<string>
using namespace std;

class Program{
    public:
    static string program_name(){
        return _program_name;
    }
    static void program_name(const string& temp){
        _program_name = temp;
    }

    static string version_stamp(){
        return _version_stamp;
    }
    static void version_stamp(const string& temp){
        _version_stamp = temp;
    }
    static int version_number(){
        return _version_number;
    }
    static void version_number(int temp){
        _version_number = temp;
    }
    static int test_run(){
        return _test_run;
    }
    static void test_run(int temp){
        _test_run = temp;
    }
    static int test_passed(){
        return _test_passed;
    }
    static void test_passed(int temp){
        _test_passed = temp;
    }
    private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _test_run;
    static int _test_passed;
}