#include <iostream>
#include "SimpleVector.h"
int main(){
  SimpleVector<int> nums(1);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  cout << nums.getElementAt(3);
  cin.get();
  return 0;
}