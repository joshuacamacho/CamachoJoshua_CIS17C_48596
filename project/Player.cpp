#include "Player.h"


Player::Player()
{
  gear = new std::map < std::string, Wearable > ;
  items = new std::list < Item > ;
  abilities = new std::vector < Talent > ;
}


Player::~Player()
{
  delete gear;
  delete items;
}
