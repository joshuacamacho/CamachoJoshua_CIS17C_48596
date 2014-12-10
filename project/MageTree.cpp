#include "MageTree.h"


MageTree::MageTree()
{
  head = new Node;
  head->t.setTalent("Arcane Bolt", "A low mana cost bolt of arcane power.", ACTIVE);
  head->numChildren = 3;
  head->children = new Node*[head->numChildren];
  worker = head->children[0];
  worker = new Node;
  worker->t.setTalent("Fireball", "High mana cost, high damage fire spell.", ACTIVE);
  worker = head->children[1];
  worker = new Node;
  worker->t.setTalent("Frostbolt","High mana cost ice spell, does damage and lowers opponent's attack.",ACTIVE);
  worker = head->children[2];
  worker = new Node;
  worker->t.setTalent("Time Bomb","Extremely high damage time magic spell, takes a turn to activate.",ACTIVE);
  worker = head;
}


MageTree::~MageTree()
{
}

void MageTree::printTree(){
  std::cout << 
    "Teir 1              __________________\n" <<
    "   	           |    Arcane Bolt   |\n" <<
    "                  /          |         \\\n" <<
    "                 /           |          \\\n"<<
    "Teir 2          /            |           \\\n"<<
    "        _______/___    ______|____    ____\______\n"<<
    "       | Fireball |   | Frostbolt |  | Time Bomb |";
}
void MageTree::printTree(t1spell t1){
  std::string fire = "xxxxxxxx";
  std::string frost = "xxxxxxxx";
  std::string time = "xxxxxxxx";
  if (t1 == FIREBALL){
    fire = "Fireball";
  }
  else if (t1 == FROSTBOLT){
    frost = "Frostbolt";
  }else if (t1 == TIMEBOMB){
    time = "Time Bomb";
  }
  std::cout <<
    "Teir 1              __________________\n" <<
    "   	           |    Arcane Bolt   |\n" <<
    "                  /          |         \\\n" <<
    "                 /           |          \\\n" <<
    "Teir 2          /            |           \\\n" <<
    "        _______/___    ______|____    ____\______\n" <<
    "       | "<<fire<<" |   | "<<frost<<" |  | "<<time<<" |";
}
