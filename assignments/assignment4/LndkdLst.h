#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <sstream>
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
    LnkdLst(const LnkdLst&);
    void append(int);
    void prepend(int);
    void insertAfter(int,int);
    void insertBefore(int, int);
    Node* first();
    Node* last();
    void extract(int);
    string toString();
    virtual ~LnkdLst();
};

#endif	/* LNKDLST_H */

