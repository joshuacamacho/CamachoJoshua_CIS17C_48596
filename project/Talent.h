#pragma once
#include <string>
#include <map>
enum tType{
  PASSIVE, ACTIVE
};
class Talent
{
private:
  tType type;
  std::map<std::string,std::string> description;
public:
  void setTalent(std::string,std::string,tType);
  std::string getName();
  std::string getDescription();
  Talent();
  ~Talent();
};

