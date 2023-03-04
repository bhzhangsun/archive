#ifndef _ZSSPTR_SHARED_PTR_HPP_
#define _ZSSPTR_SHARED_PTR_HPP_

namespace zsbh {
namespace sptr {

template <typename T>
class weak_ptr;

template <typename T>
class shared_ptr
{
	public:
		typedef T value_type;
		typedef shared_ptr<T> this_type;

	private:
		T *ptr;
		int *ctptr;		//reference conter point, express counter shared amount;

		//friends
		friend class weak_ptr<T>;
	public:
		//construct
		explicit shared_ptr(T *const p = nullptr, int *ref = nullptr) 
			: ptr(p), ctptr(ref)
		{
			if(ptr != nullptr)
			{
				if(nullptr == ctptr)
					ctptr = new int(1);
				else
					++(*ctptr);
			}
			else
				ctptr = nullptr;
		}

		//destruct
		~shared_ptr()
		{
			//freed or nullptr
			if(ptr == nullptr)
				return ;

			//real point
			if(ctptr != nullptr && --(*ctptr) == 0)
			{
				delete ptr;
				delete ctptr;
				ctptr = nullptr;
				ptr = nullptr;
			}

		}

		//copy construct
		shared_ptr(shared_ptr<T> const &b)
		{
			ptr = b.ptr;
			ctptr = b.ctptr;
			if(ctptr != nullptr)
				++(*ctptr);
		}

		//assignment
		shared_ptr<T> const& operator=(shared_ptr<T> const &b)
		{
			//prevent self-assignment
			if(this == &b)
				return *this;

			//destory *this
			if(ctptr != nullptr && --(*ctptr) == 0)
			{
				delete ptr;
				delete ctptr;
			}
				
			//assignment
			ptr = b.ptr;
			ctptr = b.ctptr;
			if(ctptr != nullptr)
				++(*ctptr);
			
		}


		//abnormal
		//operator reload
		T &operator*() const
		{
			if(ptr != nullptr)
				return *ptr;
			else
				throw "nullptr";

		}


		T *operator->() const
		{
			return ptr;
		}

		T &operator[](int i) const
		{
			if(ptr != nullptr && ctptr != nullptr)
				return ptr[i];
			else
				throw "nullptr";
				
		}

		//reset
		void reset()
		{
			//freed or nullptr
			if(ptr == nullptr)
				return ;

			//real point
			if(ctptr != nullptr && --(*ctptr) == 0)
			{
				delete ptr;
				delete ctptr;
			}
			ctptr = nullptr;
			ptr = nullptr;
		}

		//get
		T *get() const
		{
			return ptr;
		}

		bool unique() const
		{
			if(ctptr == nullptr)
				return true;
			else
				return *ctptr == 1;
		}

		int use_count() const
		{
			if(ptr == nullptr)
				return 0;
			else if(ctptr != nullptr)
				return *ctptr;
			else
				throw "point not nullptr and reference is nullptr";
		}

		void swap(shared_ptr<T> &b)
		{
			T *tmpptr = b.ptr;
			b.ptr = ptr;
			ptr = tmpptr;

			int *tmpctr = b.ctptr;
			b.ctptr = ctptr;
			ctptr = tmpctr;
		}
};

template<typename T>
void swap(shared_ptr<T> &a, shared_ptr<T> &b)
{
	a.swap(b);
}

} //namespace sptr
} //namespace zsbh


#endif
