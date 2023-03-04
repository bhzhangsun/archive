#ifndef _ZSBH_SPTR_SCOPED_ARRAY_HPP_
#define _ZSBH_SPTR_SCOPED_ARRAY_HPP_
namespace zsbh {
namespace sptr {

template <typename T>
class scoped_array
{
	public:
		typedef T value_type;
		typedef scoped_array<T> this_type;
		
	private:
		T *ptr;

		//copy construct and assignment
		scoped_array(scoped_array const &);
		scoped_array const& operator=(scoped_array const &);

		bool operator==(scoped_array const &) const;
		bool operator!=(scoped_array const &) const;

	public:
		//construct 
		explicit scoped_array(T * const p = nullptr) :ptr(p) {}

		//destruct
		~scoped_array()
		{
			if(ptr != nullptr)
				delete[] ptr;
		}
		
		//reload operator[]
		T &operator[] (int const i) const
		{
			return ptr[i];
		}

		//get point
		T *get()
		{
			return ptr;
		}

		//repace ptr for p
		void reset()
		{
			if(ptr != nullptr)
			{
				delete[] ptr;
			}
			ptr = nullptr;
		}

		//swap
		void swap(scoped_array &b)
		{
			T *tmp = b.ptr;
			b.ptr = ptr;
			ptr = tmp;
		}

};


template <typename T>
void swap(scoped_array<T> &a, scoped_array<T> &b)
{
	a.swap(b);
}

} //namesapce sptr
} //namespace zsbh

#endif //!_ZSBH_SPTR_SCOPED_ARRAY_HPP_
