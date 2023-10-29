#ifndef LEPTJSON_H__
#define LEPTJSON_H__

//value 的类型
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

//_value结构体，目前仅包含类型
typedef struct {
    lept_type type;
}lept_value;

//定义四个枚举常量，表示返回的状态
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

//将_value值，解析成 json字符串
int lept_parse(lept_value* v, const char* json);

//根据_value值，返回_value的类型
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
