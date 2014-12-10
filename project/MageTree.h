#pragma once
#include "TalentTree.h"
#include <iostream>


enum t1spell{
  FIREBALL,FROSTBOLT,TIMEBOMB
};
class MageTree : public TalentTree
{
public:
  void printTree();
  void printTree(t1spell);
  MageTree();
  ~MageTree();
};

