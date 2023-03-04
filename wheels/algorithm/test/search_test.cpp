#include "search.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int>::iterator result;
    std::vector<int> arr({3, 4, 2, 1, 45, 6, 47, 0, 98, 23});

    std::cout << "----查找存在元素----" << std::endl;
    result = zsbh::algorithm::search_linear(arr.begin(), arr.end(), 4);
    std::cout << "result:" << result - arr.begin() << std::endl;

    std::cout << "----查找不存在元素----" << std::endl;
    result = zsbh::algorithm::search_linear(arr.begin(), arr.end(), 99);
    std::cout << "result:" << result - arr.begin() << std::endl;

    std::cout << "----查找数组存在元素----" << std::endl;
    int index = zsbh::algorithm::search_array(arr, 47);
    std::cout << "result:" << index << std::endl;

    std::cout << "----查找数组不存在元素----" << std::endl;
    index = zsbh::algorithm::search_array(arr, 407);
    std::cout << "result:" << index << std::endl;
    return 0;
}