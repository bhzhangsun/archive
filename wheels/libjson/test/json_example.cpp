#include <string>
#include <iostream>
#include "json.h"

int main() {
    const std::string source = "";

    zsbh::json::Value value;
    zsbh::json::Reader reader;
    value = reader.parse(source);

    std::cout << value.stringfy() << std::endl;

    std::cout << value.style_dump() << std::endl;
    return 0;
}