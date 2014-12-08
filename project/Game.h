#pragma once
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <windows.h>

enum Status{
  CONTINUE,EXIT
};
class Game
{
private:
  Player* p;
  Status flag;
  void intro();
  void characterCreation();
  void clear();
public:
  void displayArt(std::string);
  void begin();
  Game();
  ~Game();
};