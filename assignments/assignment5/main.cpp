/* 
 * File:   Linked List
 * Author: Joshua Camacho
 */

#include <cstdlib>
#include <iostream>
#include "LnkdLst.h"



int main(int argc, char** argv) {
    LnkdLst<char> * list = new LnkdLst<char>('2');
    list->append('t');
    list->prepend('3');
    list->insertAfter(1,'r');
    list->insertBefore(0,'f');
    
    LnkdLst<char>* copy = new LnkdLst<char>('3');
    
    copy=list;
    cout<<list->toString()<<"\n";
    cout<<copy->toString();
    return 0;
}

