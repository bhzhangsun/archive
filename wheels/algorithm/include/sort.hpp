#ifndef _ZSBH_ALGORITHM_SORT_HPP_
#define _ZSBH_ALGORITHM_SORT_HPP_

#include <vector>
#include <functional>

namespace zsbh {
namespace algorithm {

template <typename Iter>
const Iter & insertion_sort(  Iter const &begin, 
            Iter const &end, 
            std::function<int(typename Iter::value_type, typename Iter::value_type)> const &compare
            /*compare 返回值大于0表示正序，即用户满意的顺序；小于0表示与正序相对的逆序。*/) {
    for(auto i = begin + 1; i != end; ++i) {
        for (auto j = i; j != begin; --j) {
            if (0 > compare(*(j - 1), *j)) {
                //无序进入
                auto tmp = *j;
                *j = *(j - 1);
                *(j - 1) = tmp;
            }
        }
    }
    return begin;
}

template < typename Iter>
const Iter & select_sort(  Iter const &begin, 
            Iter const &end, 
            std::function<int(typename Iter::value_type, typename Iter::value_type)> const &compare
            /*compare 返回值大于0表示正序，即用户满意的顺序；小于0表示与正序相对的逆序。*/) {
    for (auto i = begin; i != end; ++i) {
        Iter tmp = i;
        for(auto j = i + 1; j != end; ++j) {
            //选择正序最后的值放到最前端的位置，会导致反向排列
            //选择逆序最末尾的值放到最前面，结果是正向排列
            if (compare(*tmp, *j) < 0) {
                tmp = j;
            }
        }
        auto copy = *i;
        *i = *tmp;
        *tmp = copy;
    }
    return begin;
}

}
}

#endif //!_ZSBH_ALGORITHM_SORT_HPP_ 