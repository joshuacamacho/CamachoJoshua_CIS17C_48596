#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <sstream>
using namespace std;

template <class T>
class LnkdLst {
private:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;

public:
    LnkdLst(T);
    LnkdLst(const LnkdLst&);
    LnkdLst& operator=(const LnkdLst&);
    void append(T);
    void prepend(T);
    void insertAfter(int,T);
    void insertBefore(int, T);
    Node* first();
    Node* last();
    void extract(int);
    string toString();
    virtual ~LnkdLst();
};

#endif	/* LNKDLST_H */

