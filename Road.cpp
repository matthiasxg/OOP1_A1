//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#include "Road.hpp"

int Road::number_of_blocked_roads_ = 0;

Road::Road(bool blocked, Coordinates pos)
{
  blocked_ = blocked;
  position_ = pos;
}

void Road::print()
{
  printf("%c", blocked_ ? '%' : '#');
}
