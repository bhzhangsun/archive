#include "shared_ptr.hpp"

#ifndef _ZSBH_SPTR_WEAK_PTR_HPP
#define _ZSBH_SPTR_WEAK_PTR_HPP_

namespace zsbh {
namespace sptr {

template<typename T>
class weak_ptr
{
	public:
		typedef T value_type;
		typedef weak_ptr<T> this_type;

	private:
		T *ptr;
		int *wctptr;

	public:
	

		//construct 
		//default
		weak_ptr() : ptr(nullptr), wctptr(nullptr)
		{}

		weak_ptr(shared_ptr<T> const& sptr)
		{
			ptr = sptr.ptr;
			wctptr = sptr.ctptr;
		}

		weak_ptr(shared_array<T> const& sptr)
		{
			ptr = sptr.ptr;
			wctptr = sptr.ctptr;
		}

		//destruct 
		~weak_ptr()
		{
			ptr = nullptr;
			wctptr = nullptr;
		}

		//copy construct
		weak_ptr(weak_ptr<T> const& b)
		{
			ptr = b.ptr;
			wctptr = b.wctptr;
		}

		//assignment operator reload
		weak_ptr<T> const & operator=(weak_ptr<T> const &b)
		{

			if(this == &b)
				return *this;
			
			ptr = b.ptr;
			wctptr = b.wctptr;
			return *this;
		}

		//lock
		shared_ptr<T> lock() const
		{
			return shared_ptr<T>(ptr, wctptr);
		}

		shared_array<T> lock_array() const
		{
			return shared_array<T>(ptr, wctptr);
		}

		int use_count() const
		{
			if(ptr == nullptr)
				return 0;
			else if(wctptr != nullptr)
				return *wctptr;
			else
				throw "point is not nullptr, reference is nullptr";
		}

		bool expired()
		{
			return wctptr == nullptr;
		}

		void reset()
		{
			ptr = nullptr;
			wctptr = nullptr;
		}

		void swap(weak_ptr<T> &b)
		{
			T *tmpptr = b.ptr;
			b.ptr = ptr;
			ptr = tmpptr;

			int *tmpctr = b.wctptr;
			b.wctptr = wctptr;
			wctptr = tmpctr;
		}

		

};

template<typename T>
void swap(weak_ptr<T> &a, weak_ptr<T> &b)
{
	a.swap();
}


} //namesapce sptr
} //namesapce zsbh

#endif
