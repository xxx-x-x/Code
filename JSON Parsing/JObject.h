#pragma once
#include<variant>
#include<string>
#include<vector>
#include<map>
// JObject类是token的值
// string 类是token的键
namespace xzh
{
    enum class TYPE
    {
        T_NULL,
        T_BOOL,
        T_INT,
        T_DOUBLE,
        T_STRING,
        T_ARRAY,
        T_JOBJECT
    };
    using null_t = std::string;
    using int_t = int;
    using bool_t = bool;
    using double_t = double;
    using str_t = std::string;
    using arr_t = std::vector<JObject>;
    using map_t = std::map<std::string,JObject>;
    using value_t = std::variant<null_t,int_t,bool_t,double_t,str_t,arr_t,map_t>;

    class JObject
    {
    public:    
    private:
        TYPE m_type; 
        value_t m_value;
    };
} // namespace xzh
