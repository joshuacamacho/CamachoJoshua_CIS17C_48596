/* 
 * File:   Linked List
 * Author: Joshua Camacho
 */

#include <cstdlib>
#include <iostream>
#include "LndkdLst.h"



int main(int argc, char** argv) {
    LnkdLst *test = new LnkdLst(10);
    //test->prepend(3);
    test->append(2);
    test->append(3);
    test->prepend(4);
    test->append(9);
    test->prepend(301);
    test->extract(5);
    test->extract(4);
    test->insertAfter(3, 19);
    test->insertAfter(4, 7);
    test->insertBefore(2, 12);
    std::cout << test->toString();
    
    delete test;
    std::cout <<"\nhi\n"<< test;
    std::cin.get();
    return 0;
}

