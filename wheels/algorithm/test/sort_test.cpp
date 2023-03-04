#include "sort.hpp"
#include <iostream>
#include <vector>
#include <functional>

int main() {
    std::vector<int> arr = {3, 5, 4, 6, 7, 12, 45, 2, 34};
    std::function<int(int, int)> compare = [](int a, int b) -> int {return b - a;};
    zsbh::algorithm::select_sort(arr.begin(), arr.end(), compare);
    //zsbh::algorithm::insertion_sort(arr.begin(), arr.end(), compare);
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        if (i + 1 == arr.end()) {
            std::cout << *i << std::endl;
        } else {
            std::cout << *i << " < ";
        }
    }
    return 0;
}