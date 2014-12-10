#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Game.h"
#include "Wearable.h"
#include "Talent.h"
#include "MageTree.h"


int main(){
  /*
  srand(time(NULL));
  for (int i = 0; i < 100; i++){
    int roll = (rand() % 40)+1;
    Wearable w(roll);
    std::cout << "Slot: " << w.getSlot();
    std::cout << "\nName: " << w.getName();
    std::cout << "\nAtk:" << w.getAttack();
    std::cout << "\nDef:" << w.getDefense();
    std::cout << "\nMag:" << w.getMagic(); 
    std::cout << "\n\n";
    
    std::cin.get();
  }*/
  //Game g;
  //g.displayArt("magetree.txt");
  MageTree m;
  m.printTree(FROSTBOLT);
  std::cin.get();
  //g.begin();
  return 0;
}