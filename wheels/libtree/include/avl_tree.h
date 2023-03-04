/**
 * map底层实现，使用avl树
 * 实现avl树的基本操作
 *   @next 
 *   @before 
 *   @rotate_left
 *   @rotate_right
 *   @rotate_left_right
 *   @rotate_right_left
 *   @insert_rebalance
 *   @erase_rebalance
 *   @height
 *   @check_balance
*/

#ifndef _ZSBH_TREE_AVL_TREE_H_
#define _ZSBH_TREE_AVL_TREE_H_

namespace zsbh 
{
namespace avl 
{

struct _node_base 
{
    typedef _node_base* _base_ptr;
    typedef const _node_base* _const_base_ptr;
    typedef _node_base& _base_ref;

    unsigned int _bal_factor: 2;
    unsigned int _height: 30;
    _node_base* _parent;
    _node_base* _left;
    _node_base* _right;

    _node_base() : _bal_factor(0), _height(0), _parent(nullptr), _left(nullptr), _right(nullptr) {
    }
    static _base_ptr _minimum(_base_ptr __x) 
    {
        while (__x->_left != nullptr)
        {
            __x = __x->_left;
        }
        return __x;
    }

    static _const_base_ptr _minimum(_const_base_ptr __x)
    {
        return _minimum(__x);
    }

    static _base_ptr _maximum(_base_ptr __x)
    {
        while(__x->_right != nullptr)
        {
            __x = __x->_right;
        }
        return __x;
    }

    static _const_base_ptr _maximum(_const_base_ptr __x)
    {
        return _maximum(__x);
    }
};

template<typename _Val>
struct _node: public _node_base 
{
    typedef _node<_Val>* _link_type;
    _Val _value;
};

_node_base* _increment(_node_base* __x);
const _node_base _increment(const _node_base* __x);

_node_base* _decrement(_node_base* __x);
const _node_base _decrement(const _node_base* __x);

/**
 * iterator
*/


/**
 * 
*/
void insert_rebalance(const bool __insert_left, 
                    _node_base* __x, 
                    _node_base* __p, 
                    _node_base* __header);

void erase_rebalance(_node_base* __z,
                    _node_base& __header);



} //!namespace avl
} // !namespace zsbh

#endif //!_ZSBH_TREE_AVL_TREE_H_