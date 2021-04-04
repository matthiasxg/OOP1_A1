//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef A1_ROAD_HPP
#define A1_ROAD_HPP

#include "Field.hpp"
#include <iostream>

class Road : public Field
{
  bool blocked_;
  inline static int number_of_blocked_roads_ = 0;

  public:
    Road(bool blocked, Coordinates pos);

    static int getNumberOfBlockedRoads()
    {
      return number_of_blocked_roads_;
    }

    bool isBlocked()
    {
      return blocked_;
    }

    void print();
    ~Road();
};

#endif // A1_ROAD_HPP
