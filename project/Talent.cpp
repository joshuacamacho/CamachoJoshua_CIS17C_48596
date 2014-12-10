#include "Talent.h"


Talent::Talent()
{
}


Talent::~Talent()
{
}

void Talent::setTalent(std::string name, std::string des, tType t){
  description[name] = des;
  type = t;
}

std::string Talent::getName(){
  return description.begin()->first;
}

std::string Talent::getDescription(){
  return description.begin()->second;
}