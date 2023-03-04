#ifndef _ZSBH_JSON_PARSER_H_
#define _ZSBH_JSON_PARSER_H_

#include <string>
#include <strstream>
#include <fstream>
#include <istream>
#include <list>
#include <memory>

namespace zsbh 
{
namespace json
{

enum token_type {
    TOKEN_COMMA = 1 << 1,       //,
    // TOKEN_QUOTE = 1 << 2,       //"
    TOKEN_COLON = 1 << 3,       //:
    TOKEN_BRACE_L = 1 << 4,     //{
    TOKEN_BRACE_R = 1 << 5,     //}
    TOKEN_BRACKET_L = 1 << 6,   //[
    TOKEN_BRACKET_R = 1 << 7,   //]
    TOKEN_NULL = 1 << 8,        //null
    TOKEN_NUMBER = 1 << 9,      //^[-1-9][0-9]*$
    TOKEN_BOOLEAN = 1 << 10,    //true | false
    TOKEN_STRING = 1 << 11,     //^".*"$
    TOKEN_EOF = 1 << 12,         // 文件eof，表示token结束
    TOKEN_BLANK = 1 << 13
};

struct Token {
    token_type type_;
    std::string value_;

    operator bool() {
        return type_ != TOKEN_EOF;
    }
};

class Tokenizer
{
private:
    std::list<Token> tokens_;
    std::unique_ptr<std::istream> stream_;

    Token ReadNull();
    Token ReadBoolean(char first);
    Token ReadString();
    Token ReadNumber(char first);
public:
    Tokenizer() = delete;
    Tokenizer(const std::string& text): stream_(std::make_unique<std::strstream>(text)) {}
    Tokenizer(std::fstream& file): stream_(std::make_unique<std::fstream>(file)) {}
    ~Tokenizer() = default;

    Token next();
    int Tokenize();
};


} // !namespace json
} // !namespace zsbh

#endif // !_ZSBH_JSON_PARSER_H_