#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
using namespace std;

class LnkdLst {
private:
    struct Node{
         int data;
         Node *next;
    };
    Node *head;
    Node *worker;

public:
    LnkdLst(int);
    void append(int);
    string toString();
    virtual ~LnkdLst();
};

#endif	/* LNKDLST_H */

