/*
 * boost like smartptr
 *
 */
#ifndef _ZSBH_SPTR_SCOPED_PTR_HPP_
#define _ZSBH_SPTR_SCOPED_PTR_HPP_
namespace zsbh {
namespace sptr {
template<typename T>
class scoped_ptr
{
	public:
		typedef T value_type;
	
	private:
		T *ptr;

		scoped_ptr(scoped_ptr const &);
		template<typename O>
		scoped_ptr & operator=(scoped_ptr<O> const&);

		void operator==(scoped_ptr const &) const;
		void operator!=(scoped_ptr const &) const;

	public:
		//construct
		explicit scoped_ptr(T * const p = nullptr) : ptr(p) {}
		
		//destruct
		~scoped_ptr()		
		{
			if(ptr != nullptr) 
				delete ptr;
		}

		//reload operator*
		T &operator*() const 
		{
			return *ptr;
		}

		//reload operator->
		T *operator->() const
		{
			return ptr;
		}

		//delete ptr, and give it same type a new point
		void reset() 
		{
			if(ptr != nullptr)
			{
				delete ptr; 
				ptr = nullptr;
			}
		}

		//get point
		T *get() const
		{
			return ptr;
		}
		//
		void swap(scoped_ptr &b)
		{
			T *tmp = b.ptr;
			b.ptr = ptr;
			ptr = tmp;
		}

};

template <typename T>
void swap(scoped_ptr<T> &a, scoped_ptr<T> &b)
{
	a.swap(b);
}

} //namespace sptr
} //namespace zsbh

#endif
