//----------------------------------------------------------------------------------------------------------------------
// Assignment 1 - OOP1 SS2021
//
// Board-class represents the Board where roads and items are placed on.
//
// Author: Tutors
//----------------------------------------------------------------------------------------------------------------------
//

#include "Board.hpp"
#include "Field.hpp"
#include "Road.hpp"
#include "Item.hpp"
#include <cstdio>
/*
 * TODO begin: If you need any additional includes you can add them here.
 */

// TODO end

//----------------------------------------------------------------------------------------------------------------------
Board::Board(size_t height, size_t width, size_t nr_items, char** fields):
  height_(height),
  width_(width),
  number_items_(nr_items),
  board_(0),
  items_(0)
{
  initializeFields(fields);
}

//----------------------------------------------------------------------------------------------------------------------
Board::~Board()
{
  deleteFields();
}

//----------------------------------------------------------------------------------------------------------------------
void Board::initializeFields(char** fields)
{
  for (size_t i = 0; i < height_; i++)
  {
    std::vector<Field*> row;
    for (size_t j = 0; j < width_; j++)
    {
      char c = fields[i][j];
      if (c == '#')
      {
        row.push_back(new Road(false, {i, j}));
      }
      else if (c == '%')
      {
        row.push_back(new Road(true, {i, j}));
      }
      else if (c >= 'A' && c <= 'Z')
      {
        Item* item = new Item(c, {i, j});
        items_.push_back(item);
        row.push_back(item);
      }
      else
      {
        row.push_back(NULL);
      }
    }
    board_.push_back(row);
  }
  /* 
   * TODO begin: 
   * - iterate over the 2D-array fields
   * - create "Road" and "Item" objects on the heap and store them in the board_ std::vector
   * - add items to the items_ std::vector
   */

  // TODO end
}

//----------------------------------------------------------------------------------------------------------------------
void Board::deleteFields(void)
{
  /*
   * TODO begin:
   * - free/delete the memory of each "Road" and "Item" object on the board_
   * - if you call the destructor of a "Field" object, make sure, that it is
   *   declared as virtual - as well as the destructor of "Road" and "Item" -
   *   so that the entire "Road" or "Item" object will be destroyed
   */

  for (unsigned long i = 0; i < board_.size(); i++)
  {
    for (unsigned long j = 0; j < board_.at(i).size(); j++)
    {
      delete board_[i][j];
    }
  }

  // TODO end
}

//----------------------------------------------------------------------------------------------------------------------
Item* Board::getItemByName(std::string name)
{
  if (name.length() != 1)
    return NULL;
  char character = name[0];
  for (size_t current_item_it = 0; current_item_it < number_items_; current_item_it++)
  {
    Item* current_item = items_.at(current_item_it);
    if (current_item != NULL && current_item->getName() == character)
      return current_item;
  }
  return NULL;
}

//----------------------------------------------------------------------------------------------------------------------
bool Board::findPath(Item* from_item, Item* to_item)
{
  /*
   * TODO begin:
   * implement your path-finding algorithm here
   * if you want to use subroutines, implement them directly below this method and add them to the Board.hpp
   */

  //TODO end

  if (from_item->getPosition().column_ == to_item->getPosition().column_)
  {
    if (from_item->getPosition().row_ == to_item->getPosition().row_)
    {
      return true;
    }
  }

  if (!onBoard(from_item->getPosition()) || !onBoard(to_item->getPosition()))
  {
    return false;
  }

  std::vector<Coordinates> visited;
  if (findPath(visited, from_item, to_item))
  {
    return true;
  }

  return false;
}

//----------------------------------------------------------------------------------------------------------------------
/*
 * TODO begin: If you need any helper methods for the path finding, feel free
 * to implement them here.
 */

bool Board::findPath(std::vector<Coordinates> visited, Field* from, Item* to_item)
{
  std::vector<Coordinates> neighbours = getNeighbours(from->getPosition());

  for (Coordinates neighbour : neighbours)
  {
    if (!check_visit(visited, neighbour))
    {
      visited.push_back(neighbour);
      Field* check = board_[neighbour.row_][neighbour.column_];
      if (check != NULL)
      {
        if (neighbour.column_ == to_item->getPosition().column_ &&
            neighbour.row_ == to_item->getPosition().row_) {
          return true;
        }

        if (!check->isBlocked())
        {
          if(findPath(visited, check, to_item))
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool Board::check_visit(std::vector<Coordinates> visited, Coordinates coordinates)
{
  if (visited.empty())
  {
    return false;
  }

  for (Coordinates coord : visited)
  {
    if (coord.row_ == coordinates.row_ && coord.column_ == coordinates.column_)
    {
      return true;
    }
  }
  return false;
}

std::vector<Coordinates> Board::getNeighbours(Coordinates coordinates)
{
  std::vector<Coordinates> neighbours;

  if (onBoard({coordinates.row_-1, coordinates.column_}))
  {
    neighbours.push_back({coordinates.row_-1,coordinates.column_});
  }

  if (onBoard({coordinates.row_+1, coordinates.column_}))
  {
    neighbours.push_back({coordinates.row_+1,coordinates.column_});
  }

  if (onBoard({coordinates.row_, coordinates.column_-1}))
  {
    neighbours.push_back({coordinates.row_,coordinates.column_-1});
  }

  if (onBoard({coordinates.row_, coordinates.column_+1}))
  {
    neighbours.push_back({coordinates.row_,coordinates.column_+1});
  }

  return neighbours;
}

bool Board::onBoard(Coordinates coordinates)
{
  if (coordinates.row_ >= 0 && coordinates.row_ < height_)
  {
    if (coordinates.column_ >= 0 && coordinates.column_ < width_)
    {
      return true;
    }
  }
  return false;
}

// TODO end

//----------------------------------------------------------------------------------------------------------------------
void Board::print(void)
{
  printLines();

  for (size_t row = 0; row < height_; row++)
  {
    printf("│");
    for (size_t column = 0; column < width_; column++)
    {
      if (board_.at(row).at(column))
        board_.at(row).at(column)->print();
      else
        printf(" ");
    }
    printf("│\n");
  }

  printLines();
}

//----------------------------------------------------------------------------------------------------------------------
void Board::printLines(void)
{
  printf("┼");
  for (size_t column = 0; column < width_; column++)
  {
    printf("─");
  }
  printf("┼\n");
}
