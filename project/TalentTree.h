#pragma once
#include "Talent.h"

struct Node{
  Node** children;
  int numChildren;
  Talent t;
};
class TalentTree
{
  
public:
  Node* head;
  Node* worker;
  TalentTree();
  ~TalentTree();
};

