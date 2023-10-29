#include "Parser.h"
#include "JObject.h"

namespace xzh
{
    //跳过空白字符，以及跳过注释
    char Parser::get_next_token()
    {
        while (std::isspace(m_str[m_idx]))
        {
            m_idx++;
        }
        if(m_idx >= m_str.size())
        {
            throw std::logic_error("unexpected character in parse json");
        }
        skip_comment();
        return m_str[m_idx];
    }

    JObject Parser::parse_null()
    {
        if(m_str.compare(m_idx,4,"null") == 0)
        {
            m_idx += 4;
            return {};
        }
        throw std::logic_error("parse null error");
    }

    JObject Parser::parse_bool()
    {
        if(m_str.compare(m_idx,4,"true") == 0)
        {
            m_idx += 4;
            return "true";
        }
        if(m_str.compare(m_idx,5,"false") == 0)
        {
            m_idx += 5;
            return "false";
        }
    }
    JObject Parser::parse_number(){
         auto pos = m_idx;
        //integer part
        if (m_str[m_idx] == '-')
        {
            m_idx++;
        }
        if (isdigit(m_str[m_idx]))
            while (isdigit(m_str[m_idx]))
                m_idx++;
        else
        {
            throw std::logic_error("invalid character in number");
        }

        if (m_str[m_idx] != '.')
        {
            return (int) strtol(m_str.c_str() + pos, nullptr, 10);
        }

        //decimal part
        if (m_str[m_idx] == '.')
        {
            m_idx++;
            if (!std::isdigit(m_str[m_idx]))
            {
                throw std::logic_error("at least one digit required in parse float part!");
            }
            while (std::isdigit(m_str[m_idx]))
                m_idx++;
        }
        return strtof64(m_str.c_str() + pos, nullptr);
    }
    JObject Parser::parse_array()
    {
        JObject arr((list_t()));//得到list类型的JObject
        m_idx++;
        char ch = get_next_token();
        if (ch == ']')
        {
            m_idx++;
            return arr;
        }
        while (true)
        {
            arr.push_back(parse());
            ch = get_next_token();
            if (ch == ']')
            {
                m_idx++;
                break;
            }
            if (ch != ',') //如果不是逗号
            {
                throw std::logic_error("expected ',' in parse list");
            }
            //跳过逗号
            m_idx++;
        }
        return arr;
    }
    JObject Parser::parse_jobject()
    {
        JObject dict((dict_t()));//得到dict类型的JObject
        m_idx++;
        char ch = get_next_token();
        if (ch == '}')
        {
            m_idx++;
            return dict;
        }
        while (true)
        {
            //解析key
            string key = std::move(parse().Value<string>());
            ch = get_next_token();
            if (ch != ':')
            {
                throw std::logic_error("expected ':' in parse dict");
            }
            m_idx++;

            //解析value
            dict[key] = parse();
            ch = get_next_token();
            if (ch == '}')
            {
                m_idx++;
                break; //解析完毕
            }
            if (ch != ',')//没有结束，此时必须为逗号
            {
                throw std::logic_error("expected ',' in parse dict");
            }
            //跳过逗号
            m_idx++;
        }
        return dict;
    }
    JObject Parser::parse()
    {
        char token = get_next_token();
        if(token == 'n')
        {
            return parse_null();
        }
        if(token == 't' || token == 'f')
        {
            return parse_bool();
        }
        if(token == '-'|| std::isdigit(token))
        {
            return parse_number();
        }
        if(token == '\"')
        {
            return parse_string();
        }
        if(token == '[')
        {
            return parse_array();
        }
        if(token == '{')
        {
            return parse_jobject();
        }
        throw std::logic_error("unexpected character in parse json");
    }
} // namespace xzh
