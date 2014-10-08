/* 
 * File:   Linked List
 * Author: Joshua Camacho
 */

#include <cstdlib>
#include "LndkdLst.h"
using namespace std;


int main(int argc, char** argv) {
    LnkdLst *test = new LnkdLst(2);
    test->append(2);
    delete test;
    return 0;
}

