#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <sstream>
using namespace std;
template <class T> struct Node{
         T data;
         Node *next;
    };
template <class T> class LnkdLst {
private:
    
    Node<T> *head;
    Node<T> *worker;

public:
    LnkdLst(T);
    LnkdLst(const LnkdLst&);
    LnkdLst& operator=(const LnkdLst&);
    void append(T);
    void prepend(T);
    void insertAfter(int,T);
    void insertBefore(int, T);
    Node<T>* first();
    Node<T>* last();
    void extract(int);
    string toString();
    virtual ~LnkdLst();
    

    
    
    
    
};

template <class T> LnkdLst<T>::LnkdLst(T x){
  this->head = new Node<T>;
  this->head->data = x;
  this->head->next = NULL;
  this->worker = this->head;
}

template <class T> LnkdLst<T>::LnkdLst(const LnkdLst& old){
  Node<T>* temp = old.head;
  this->head = new Node<T>;
  this->head->data = old.head->data;
  this->worker = this->head;
  while (temp->next != NULL){
    this->worker->next = new Node<T>;
    this->worker = this->worker->next;
    temp = temp->next;
    this->worker->data = temp->data;
    this->worker->next = NULL;
  } 
  this->worker = this->head;
}

template <class T> LnkdLst<T>& LnkdLst<T>::operator=(const LnkdLst& old){
  Node<T>* current;
  worker = head;
  while (worker->next != NULL){
    current = worker;
    worker = worker->next;
    delete current;
  }
  current = old.head;
  worker = head;
  
  while (current->next != NULL){
    worker->next = new Node<T>;
    worker->data = current->data;
    worker = worker->next;
    current = current->next;
  }
  worker->next = NULL;
  return *this;
}

template <class T> void LnkdLst<T>::append(T x){
  this->worker = head;
  while (this->worker->next != NULL){
    this->worker = this->worker->next;
  }
  this->worker->next = new Node<T>;
  this->worker = this->worker->next;
  this->worker->data = x;
  this->worker->next = NULL;
}

template <class T> string LnkdLst<T>::toString(){
  stringstream ss;
  this->worker = this->head;
  while (this->worker->next != NULL){
    ss << this->worker->data << " ";
    this->worker = this->worker->next;
  }
  ss << this->worker->data;
  string x = ss.str();
  return x;
}

template <class T>
void LnkdLst<T>::prepend(T x){
  Node<T> *before = this->head;
  this->head = NULL;
  this->head = new Node<T>;
  this->head->data = x;
  this->head->next = before;
  before = NULL;
  this->worker = this->head;
}

template <class T>
void LnkdLst<T>::insertAfter(int index, T x){
    Node<T>* temp;
    Node<T>* newnode = new Node<T>;
    newnode->data = x;
    this->worker = this->head;
    for (int i = 0; i < index+1; i++){
      temp = this->worker;
      this->worker = this->worker->next;
    }
    temp->next = newnode;
    newnode->next = this->worker;
}

template <class T>
void LnkdLst<T>::insertBefore(int index, T x){
  if (index == 0) prepend(x);
  else{
    Node<T>* temp;
    Node<T>* newnode = new Node<T>;
    newnode->data = x;
    this->worker = this->head;
    temp = this->worker;
    for (int i = 0; i < index; i++){
      temp = this->worker;
      this->worker = this->worker->next;
    }
    temp->next = newnode;
    newnode->next = this->worker;
  }
}

template <class T> LnkdLst<T>::~LnkdLst(){
  Node<T>* current = head;
  while (current != NULL){
    this->worker = current;
    current = current->next;
    delete this->worker;
    
  }
  this->head = NULL;
}

template <class T>
Node<T>* LnkdLst<T>::first(){
  return this->head;
}

template <class T>
Node<T>* LnkdLst<T>::last(){
  Node<T>* last = this->head;
  while (last->next!=NULL){
   last = last->next;
  }
  return last;
}

template <class T>
void LnkdLst<T>::extract(int index){
  Node<T>* temp;
  if (index > 1){
    temp = this->head;
    for (int i = 0; i < index; i++){
      if (temp->next != NULL){
        this->worker = temp;
        temp = temp->next;
      }
    }
    if (temp != last()){
      this->worker->next = temp->next;
    }
    else{
      this->worker->next = NULL;
    }
    delete temp;
  }
  else if (index == 0){
    temp = this->head;
    this->head = head->next;
    delete temp;
  }
}
#endif	/* LNKDLST_H */

