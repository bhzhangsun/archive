#ifndef _ZSBH_ALGORITHM_SEARCH_HPP_
#define _ZSBH_ALGORITHM_SEARCH_HPP_

namespace zsbh {
namespace algorithm {

template <typename Iter>
const Iter search_linear(Iter const &begin, Iter const &end, typename Iter::value_type const &value) {
    for (auto i = begin; i != end; ++i) {
        if (*i == value) {
            return i;
        }
    }
    return end;
}

template <typename Ty> 
int search_array(Ty const &arr, typename Ty::value_type const &value) {
    auto it = search_linear(arr.begin(), arr.end(), value);
    if (it != arr.end()) {
        return it - arr.begin();
    } else {
        return -1;
    }
}

}
}

#endif //!_ZSBH_ALGORITHM_SEARCH_HPP_