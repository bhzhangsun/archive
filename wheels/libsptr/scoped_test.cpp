#include "scoped_ptr.hpp"
#include "scoped_array.hpp"
#include <iostream>

#include <string.h>
using std::cout;
using std::endl;
using zsbh::sptr::scoped_ptr;
using zsbh::sptr::scoped_array;

int main()
{

	scoped_ptr<int> ptr1(new int(1));
	cout << *ptr1 << endl;

	scoped_ptr<int> ptr2(new int(4));
	cout << *ptr2 << endl;


	ptr1.swap(ptr2);
	
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	swap(ptr1, ptr2);
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;
	
//	ptr1.reset(ptr2.get());

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

//	ptr1.swap(ptr2);
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	ptr1.reset(); //doblue free

/*
	scoped_array<char> ptr1(new char[25]);
	scoped_array<char> ptr2(new char[25]);

	strncpy(ptr1.get(), "This is point one", 25);
	strncpy(ptr2.get(), "This is point two", 25);

	cout << ptr1.get() << endl;
	cout << ptr2.get() << endl;

	ptr1.swap(ptr2);
	
	cout << ptr1.get() << endl;
	cout << ptr2.get() << endl;

	swap(ptr1, ptr2);
	cout << ptr1.get() << endl;
	cout << ptr2.get() << endl;

	ptr1.reset(new char[25]);
	strncpy(ptr1.get(), "Repace", 25);

	cout << ptr1.get() <<endl;
*/
	return 0;

}
