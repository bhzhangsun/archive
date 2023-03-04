#include <iostream>
#include <string>
#include <thread>
#include "singleton.hpp"
using namespace design_pattern;
using std::thread;
using std::string;
using std::cout;
using std::endl;


void GetInstance()
{
	cout << "Lazy mode<string>:" << SingletonHungry<string>::Instance() << endl;
	cout << "Hungry mode<int>:" << SingletonLazy<int>::Instance() << endl;
}

int main()
{
	thread thd1(GetInstance);
	thread thd2(GetInstance);

	thd1.join();
	thd2.join();

	return 0;
}
