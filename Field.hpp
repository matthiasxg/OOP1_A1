//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Author: Matthias Grill, 12007662
//----------------------------------------------------------------------------------------------------------------------
//

#ifndef A1_FIELD_HPP
#define A1_FIELD_HPP

#include <cstdio>

typedef struct _Coordinates_
{
  size_t row_;
  size_t column_;
} Coordinates;

class Field
{
  inline static int counter_ = 0;

  protected:
    int field_id_;
    Coordinates position_;

  public:
    Field() = default;
    Field(Coordinates pos) : field_id_{counter_++}, position_(pos) {}

    int getFieldId()
    {
      return field_id_;
    }

    Coordinates getPosition()
    {
      return position_;
    }

    void setPosition(Coordinates pos)
    {
      position_ = pos;
    }

    virtual bool isBlocked() = 0;
    virtual void print() = 0;
    virtual ~Field() = default;
};


#endif // A1_FIELD_HPP
