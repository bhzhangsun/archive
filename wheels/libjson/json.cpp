#include "json.h"
#include "parser.h"

namespace zsbh {
namespace json
{
Reader::Reader(std::istream &stream): stream_(stream) {

}

Reader::Reader(const std::string &str) {

}

void Reader::parse(std::istream &stream) {

}

void Reader::parse(const std::string &str) {

}

std::string Value::style_dump() {

}
std::string Value::stringfy() {

}

template <typename T>
int Value::append(const std::string& key, const T &value) {

}

int Value::erase(const std::string& key) {

}

} // namespace json
} // namespace zsbh