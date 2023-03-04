#include <mutex>
#include <string>
#include <iostream>

#ifndef _DESIGN_PATTERN_SINGLETON_PATTERN_SINGLETON_
#define _DESIGN_PATTERN_SINGLETON_PATTERN_SINGLETON_

namespace design_pattern
{
/**
 * lazy mode
 */
template <typename Ty>
class SingletonLazy
{
private:
	SingletonLazy() {}
	static Ty instance_;

public:
	static Ty * Instance()
	{
		return &instance_;
	}

};

template <typename Ty>
Ty SingletonLazy<Ty>::instance_;

/**
 * hungry mode
 */
template <typename Ty>
class SingletonHungry
{
private:
	SingletonHungry() {}
	static Ty *pinstance_;

public:
	static Ty *Instance()
	{
		if (nullptr == pinstance_)
		{
			std::mutex mtx;
			mtx.lock();
			if (nullptr == pinstance_)
				pinstance_ = new Ty;
			mtx.unlock();
		}
		return pinstance_;
	}

};
template <typename Ty>
Ty * SingletonHungry<Ty>::pinstance_ = nullptr;
}


#endif //!_DESIGN_PATTERN_SINGLETON_PATTERN_SINGLETON_
