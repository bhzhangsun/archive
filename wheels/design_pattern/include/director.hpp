#include <iostream>
#include "human.hpp"

#ifndef _DESIGN_PATTERN_BUILDER_DIRECTOR_HPP_
#define _DESIGN_PATTERN_BUILDER_DIRECTOR_HPP_

namespace design_pattern 
{

class Human;

class Director
{
public:
  Director(Human *ptr)
  {
    phuman_ = ptr;
  }

  void Construct()
  {
    phuman_->Head();
    phuman_->Features();
    phuman_->Body();
    phuman_->Arm();
    phuman_->Lag();
    phuman_->Foot();
  }
private:
  Human *phuman_;
};

}

#endif // !_DESIGN_PATTERN_BUILDER_DIRECTOR_HPP_