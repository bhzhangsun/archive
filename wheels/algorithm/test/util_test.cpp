#include "util.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> arr = {3, 4, 2, 1, 45, 6, 47, 0, 98, 23};
    std::cout << "-----print_array(arr.begin(), arr.end())-----" << std::endl;
    zsbh::common::print_array(arr.begin(), arr.end());
    std::cout << std::endl << "-----print_array(arr.begin(), arr.end(), printer)-----" << std::endl;
    zsbh::common::print_array(arr.begin(), arr.end(), [](int const &elem) -> void {
        std::cout << elem << "-";
    });
    std::cout << std::endl << "-----print_array(arr, printer)-----" << std::endl;
    zsbh::common::print_array(arr, [](int const &elem) -> void {
        std::cout << "$" << elem << " ";
    });
    std::cout << std::endl;
    return 0;
}