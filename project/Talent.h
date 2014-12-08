#pragma once
#include <string>
enum tType{
  PASSIVE, ACTIVE
};
class Talent
{
private:
  tType type;
  std::string description;
  std::string name;
public:
  Talent();
  ~Talent();
};

