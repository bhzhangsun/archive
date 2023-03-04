#ifndef _DESIGN_PATTERN_PROTOTYPE_PROTOTYPE_HPP_
#define _DESIGN_PATTERN_PROTOTYPE_PROTOTYPE_HPP_

namespace design_pattern
{

class Prototype
{
public:
	virtual Prototype *Clone()const = 0;
};

class ConcretePrototype : public Prototype
{
public:
	ConcretePrototype() {}
	ConcretePrototype(ConcretePrototype const &b) {}
	Prototype* Clone() const
	{
		return new ConcretePrototype(*this);
	}
};
}

#endif // !_DESIGN_PATTERN_PROTOTYPE_PROTOTYPE_HPP_
