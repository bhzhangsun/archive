#ifndef _ZSBH_JSON_JSON_H_
#define _ZSBH_JSON_JSON_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <iostream>

namespace zsbh
{
namespace json
{

typedef std::string key_type;

enum data_type {
    NUMBER_INT_TYPE,
    NUMBER_FLOAT_TYPE,
    STRING_TYPE,
    BOOLEAN_TYPE,
    NULL_TYPE,
    ARRAY_TYPE,
    OBJECT_TYPE
};


class Value {
public: 
    typedef std::map<key_type, std::tuple<key_type, data_type>> value_type;

private:
    value_type value_;

public:
    std::string style_dump();
    std::string stringfy();

    template <typename T>
    int append(const std::string& key, const T &value);

    int erase(const std::string& key);
};

union data_value {
    long long int int_data;
    double float_data;
    std::string string_data;
    bool bool_data;
    char* null_data;
    std::vector<data_value> array_data;
    Value object_data;
};


class Reader {
private:
    std::istream stream_;
public:
    Reader() = default;

    Reader(std::istream &stream);
    Reader(const std::string &str);

    Value parse(std::istream &stream);
    Value parse(const std::string &str);
};

} // namespace json
} // namespace zsbh


#endif // !_ZSBH_JSON_JSON_H_