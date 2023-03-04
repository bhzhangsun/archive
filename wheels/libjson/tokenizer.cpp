// #include <sstream>
// #include <fstream>
#include <string>
#include "tokenizer.h"

namespace zsbh
{
namespace json
{

Token Tokenizer::ReadString() {
    std::string str = "\"";
    char ch = '\"';
    char surfix = '\0';
    do
    {   
        if (surfix == '\\') {
            stream_->get(ch);
            str.append(1, ch);
            surfix = '\0';
        }
        stream_->get(ch);
        str.append(1, ch);
        surfix = ch;
    } while (!stream_->eof() && !stream_->bad() && ch != '\"');

    return Token{TOKEN_STRING, str}; // 不包含引号的字符串
}

Token Tokenizer::ReadBoolean(char val) {
    char ch;
    std::string str = "" + val;

    do {
        stream_->get(ch);
        str.append(1, ch);
    } while (!stream_->eof() && !stream_->bad() && str != "true" && str != "false");
    
    return Token{TOKEN_BOOLEAN, str};
}

Token Tokenizer::ReadNull() {
    char ch;
    std::string str = "n";

    do {
        stream_->get(ch);
        str.append(1, ch);
    } while (!stream_->eof() && !stream_->bad() && str != "null");
    
    return Token{TOKEN_NULL, str};
}

Token Tokenizer::ReadNumber(char first) {
    char ch;
    std::string str = "" + first;
    char surfix = first;
    do
    {
        stream_->get(ch);
        if (ch - '0' > 0 && ch - '0' < 10) {
            str.append(1, ch);
        } else if (ch == '0') {

        }
        /* code */
    } while (true);
    
    
}

Token Tokenizer::next() 
{
    if (stream_->eof()) {
        return Token{TOKEN_EOF, ""};
    }
    Token token;
    char curr;

    stream_->get(curr);
    switch(curr) {
        case '{':
            token = Token{TOKEN_BRACE_L, "{"};
            break;
        case '}':
            token = Token{TOKEN_BRACE_R, "}"};
            break;
        case '[':
            token = Token{TOKEN_BRACKET_L, "["};
            break;
        case ']':
            token = Token{TOKEN_BRACKET_R, "]"};
            break;
        case ':':
            token = Token{TOKEN_COLON, ":"};
            break;
        case ',':
            token = Token{TOKEN_COMMA, ","};
            break;
        case '"':
            token = ReadString();
            break;
        case 't':
        case 'f':
            token = ReadBoolean(curr);
            break;
        case 'n':
            token = ReadNull();
            break;
        default:
            if (curr - '0' >= 0 && curr - '0' < 10 || curr == '-') {
                token = ReadNumber(curr);
            } else {
                token = Token{TOKEN_BLANK, ""};
            }
    }

}

int Tokenizer::Tokenize() 
{
    Token node;
    while (node = this->next()) 
    {
        tokens_.push_back(node);
    }
}

} // !namespace json  
} // !namespace zsbh
