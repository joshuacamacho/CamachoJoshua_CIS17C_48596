#pragma once
#include <string>
class Item
{
private:
  std::string name;
  std::string description;
  int itemproperty;
public:
  void use();
  Item();
  ~Item();
};

