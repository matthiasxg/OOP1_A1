//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef A1_ITEM_HPP
#define A1_ITEM_HPP

#include "Field.hpp"

class Item : public Field
{
  char name_ = {0};

  public:

    Item(char name, Coordinates pos);

    char getName()
    {
      return name_;
    }

    bool isBlocked()
    {
      return true;
    }

    void print();
};


#endif // A1_ITEM_HPP
