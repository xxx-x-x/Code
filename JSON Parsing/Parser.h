#pragma once
#include "JObject.h"
//解析器类，用来解析JSON字符串
namespace xzh
{
    class Parser
    {
    private:
    public:
        JObject parse();// 解析字符串，返回JObject值
        char get_next_token();
        JObject parse_null();//解析字符串，返回 null 值
        JObject parse_bool();//解析字符串，返回 bool 值
        JObject parse_number();//解析字符串，返回 number 值
        JObject parse_string();//解析字符串，返回 string 值
        JObject parse_array();//解析字符串，返回 array 值
        JObject parse_jobject();//解析字符串，返回 jobject 值
    };
} // namespace XZH
