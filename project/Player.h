#pragma once
#include <string>
#include <map>
#include <list>
#include "Item.h"
#include "Talent.h"
#include "Wearable.h"
#include <vector>
class Player
{
private:
  float health;
  std::string race;
  std::string job;
  std::map<std::string, Wearable>* gear;
  std::list<Item>* items;
  std::vector<Talent>* abilities;
public:
  float getHealth();
  std::string getRace();
  std::map<std::string, Wearable>* getGear();
  std::string getJob();
  std::list<Item>* getItems();
  std::vector<Talent>* getAbilities();
  void setPlayer(
    float,
    std::string,
    std::string,
    std::map<std::string, Wearable>*,
    std::list<Item>*,
    std::vector<Talent>*);
  Player();
  ~Player();
};

