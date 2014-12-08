#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
//Armor and Weapon Class
//Item levels are from 1-40
enum Slot{
  HEAD, CHEST, LEGS, FEET, ARMS, GLOVES, WEAPON
};
enum Type{
  FIGHTER,MAGE
};
class Wearable
{
private:
  std::string name;
  int defense;
  int magic;
  int attack;
  int ilevel;
  Slot slot;
  Type type;
  void generateArmor();
  void generateWeapon();
  std::string baseName();
public:
  Wearable(int);
  ~Wearable();
  int getDefense();
  int getMagic();
  int getAttack();
  std::string getName();
  std::string getSlot();
};

