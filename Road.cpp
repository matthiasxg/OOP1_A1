//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#include "Road.hpp"

Road::Road(bool blocked, Coordinates pos)
{
  blocked_ = blocked;
  position_ = pos;
  if (blocked)
  {
    number_of_blocked_roads_++;
  }
}

Road::~Road()
{
  if (blocked_)
  {
    number_of_blocked_roads_--;
  }
}

void Road::print()
{
  printf("%c", blocked_ ? '%' : '#');
}
