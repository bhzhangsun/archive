#include "shared_ptr.hpp"
#include "shared_array.hpp"
#include "weak_ptr.hpp"

#include <iostream>
using std::cout;
using std::endl;

using zsbh::sptr::shared_ptr;
using zsbh::sptr::shared_array;
using zsbh::sptr::weak_ptr;

int main()
{

	shared_array<int> ptr1(new int(1));
	shared_array<int> ptr2(new int(2));

	cout << "ptr1, ptr2 just be maked" << endl;
	try
	{
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	}
	catch(char const *str)
	{
		cout << str << endl;
	}

	ptr1.swap(ptr2);

	cout << "ptr1, ptr2 just be exchanged" << endl;
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	shared_array<int> ptr3;
	ptr3 = ptr1;
	shared_array<int> ptr4(ptr2);

	cout << "ptr3, ptr4 just be copy" << endl;
	cout << *ptr3 << endl;
	cout << *ptr4 << endl;


	cout << "ptr1, ptr2 reference count" << endl;
	cout << ptr3.use_count() << endl;
	cout << ptr4.use_count() << endl;

	cout << "get() method" <<endl;
	cout << "ptr4.get\t" << ptr3.get() <<endl;
	cout << "ptr4.get\t" << ptr4.get() <<endl;

	ptr4.reset();
	cout << ptr4.use_count() <<endl;
	cout << ptr2.use_count() <<endl;

	cout << ptr4.unique() << endl;
	cout << ptr2.unique() << endl;


	//weak_ptr
	weak_ptr<int> ptr5(ptr3);
	cout << ptr5.use_count() <<endl;

	weak_ptr<int> ptr6(ptr5);
	cout << ptr6.use_count() <<endl;

	shared_array<int> ptr7 = ptr5.lock_array();
	cout << ptr7.use_count() <<endl;

	weak_ptr<int> c;
	c = ptr5;
	cout << ptr5.expired() << endl;
	ptr5.reset();
	cout << ptr5.expired() << endl;
	


	return 0;
}


/*
int main()
{

	shared_ptr<int> ptr1(new int(1));
	shared_ptr<int> ptr2(new int(2));

	cout << "ptr1, ptr2 just be maked" << endl;
	try
	{
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	}
	catch(char const *str)
	{
		cout << str << endl;
	}

	ptr1.swap(ptr2);

	cout << "ptr1, ptr2 just be exchanged" << endl;
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	shared_ptr<int> ptr3;
	ptr3 = ptr1;
	shared_ptr<int> ptr4(ptr2);

	cout << "ptr3, ptr4 just be copy" << endl;
	cout << *ptr3 << endl;
	cout << *ptr4 << endl;


	cout << "ptr1, ptr2 reference count" << endl;
	cout << ptr3.use_count() << endl;
	cout << ptr4.use_count() << endl;

	cout << "get() method" <<endl;
	cout << "ptr4.get\t" << ptr3.get() <<endl;
	cout << "ptr4.get\t" << ptr4.get() <<endl;

	ptr4.reset();
	cout << ptr4.use_count() <<endl;
	cout << ptr2.use_count() <<endl;

	cout << ptr4.unique() << endl;
	cout << ptr2.unique() << endl;


	//weak_ptr
	weak_ptr<int> ptr5(ptr3);
	cout << ptr5.use_count() <<endl;

	weak_ptr<int> ptr6(ptr5);
	cout << ptr6.use_count() <<endl;

	shared_ptr<int> ptr7 = ptr5.lock();
	cout << ptr7.use_count() <<endl;

	weak_ptr<int> c;
	c = ptr5;
	cout << ptr5.expired() << endl;
	ptr5.reset();
	cout << ptr5.expired() << endl;
	


	return 0;
}

*/
