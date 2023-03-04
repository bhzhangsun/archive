#ifndef _DESIGN_PATTERN_COMPOSITE_COMPOSITE_HPP_
#define _DESIGN_PATTERN_COMPOSITE_COMPOSITE_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
using std::find;
using std::vector;
using std::cout;
using std::endl;

namespace design_pattern
{

class Compnent
{
public:
	virtual ~Compnent() {}
	virtual void Add(Compnent * const ) {}
	virtual void Remove(Compnent * const ) {}
	virtual Compnent * GetChild(int) { return nullptr; }
	virtual void Operation() = 0;
};

class Finance : public Compnent
{
public:
	void Operation()
	{
		cout << "Finance : Operation()" << endl;
	}
};

class HumanResource : public Compnent
{
public:
	void Operation()
	{
		cout << "HumanResource : Operation()" << endl;
	}
};

class Filiale : public Compnent
{
private:
	vector<Compnent *> vcomp_;

public:
	void Add(Compnent * const ptr)
	{
		vcomp_.push_back(ptr);
	}

	void Remove(Compnent * const ptr)
	{
		vector<Compnent *>::iterator it = find(vcomp_.begin(), vcomp_.end(), ptr);
		if(it != vcomp_.end())
			vcomp_.erase(it);
	}

	Compnent * GetChild(int idx)
	{
		return vcomp_[idx];
	}

	void Operation()
	{
		cout << "Filiale : Operation()" << endl;

		vector<Compnent *>::iterator it = vcomp_.begin();
		while (it != vcomp_.end())
		{
			cout << "--";
			(*it)->Operation();
			++it;
		}

	}
};

class Office : public Compnent
{
private:
	vector<Compnent *> vcomp_;

public:
	
	void Add(Compnent * const ptr)
	{
		vcomp_.push_back(ptr);
	}

	void Remove(Compnent * const ptr)
	{
		vector<Compnent *>::iterator it = find(vcomp_.begin(), vcomp_.end(), ptr);

		if (it != vcomp_.end())
			vcomp_.erase(it);
	}

	Compnent * GetChild(int idx)
	{
		return vcomp_[idx];
	}

	void Operation()
	{
		cout << "Office : Operation()" << endl;
		
		vector<Compnent *>::iterator it = vcomp_.begin();
		while (it != vcomp_.end())
		{
			cout << "--";
			(*it)->Operation();
			++it;
		}
	}
};
}

#endif // !_DESIGN_PATTERN_COMPOSITE_COMPOSITE_HPP_