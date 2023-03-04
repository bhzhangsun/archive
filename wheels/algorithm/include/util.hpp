#ifndef _ZSBH_COMMON_UTIL_HPP_
#define _ZSBH_COMMON_UTIL_HPP_

#include <functional>
#include <iostream>

namespace zsbh {
namespace common {

template <typename Iter>
void print_array(Iter const &begin, Iter const &end,
                std::function<void(typename Iter::value_type)> const &printer = 
                    [](typename Iter::value_type elem) -> void{std::cout << elem << " ";}) {
    for (auto i = begin; i != end; ++i) {
        printer(*i);
    }
} 

template <typename Ty>
void print_array(Ty const &arr, std::function<void(typename Ty::value_type)> const &printer = 
                    [](typename Ty::value_type elem) -> void{std::cout << elem << " ";}) {
    print_array(arr.begin(), arr.end(), printer);
}

} // namespace common    
} // namespace zsbh

#endif //! _ZSBH_COMMON_UTIL_HPP_