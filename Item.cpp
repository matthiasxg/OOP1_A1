//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#include "Item.hpp"
#include <iostream>

Item::Item(char name, Coordinates pos)
{
  name_ = name;
  position_ = pos;
}

void Item::print()
{
  printf("%c", name_);
}
