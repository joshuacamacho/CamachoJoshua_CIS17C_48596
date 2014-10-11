/* 
 * File:   LndkdLst.cpp
 * Author: Joshua Camacho
 * Created on October 8, 2014, 9:09 AM
 */

#include "LndkdLst.h"
template <class T> 
LnkdLst::LnkdLst(T x){
  this->head = new Node;
  this->head->data = x;
  this->head->next = NULL;
  this->worker = this->head;
}

template <class T>
LnkdLst::LnkdLst(const LnkdLst& old){
  Node* temp = old.head;
  this->head = new Node;
  this->head->data = old.head->data;
  this->worker = this->head;
  while (temp->next != NULL){
    this->worker->next = new Node;
    this->worker = this->worker->next;
    temp = temp->next;
    this->worker->data = temp->data;
    this->worker->next = NULL;
  } 
  this->worker = this->head;
}

template <class T>
LnkdLst& LnkdLst::operator=(const LnkdLst& old){
  Node* current;
  worker = head;
  while (worker->next != NULL){
    current = worker;
    worker = worker->next;
    delete current;
  }
  current = old.head;
  worker = head;
  
  while (current->next != NULL){
    worker->next = new Node;
    worker->data = current->data;
    worker = worker->next;
    current = current->next;
  }
  worker->next = NULL;
  return *this;
}

template <class T>
void LnkdLst::append(T x){
  this->worker = head;
  while (this->worker->next != NULL){
    this->worker = this->worker->next;
  }
  this->worker->next = new Node;
  this->worker = this->worker->next;
  this->worker->data = x;
  this->worker->next = NULL;
}

template <class T>
string LnkdLst::toString(){
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
void LnkdLst::prepend(T x){
  Node *before = this->head;
  this->head = NULL;
  this->head = new Node;
  this->head->data = x;
  this->head->next = before;
  before = NULL;
  this->worker = this->head;
}

template <class T>
void LnkdLst::insertAfter(int index, T x){
    Node* temp;
    Node* newnode = new Node;
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
void LnkdLst::insertBefore(int index, T x){
  if (index == 0) prepend(x);
  else{
    Node* temp;
    Node* newnode = new Node;
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

template <class T>
LnkdLst::~LnkdLst(){
  Node* current = head;
  while (current != NULL){
    this->worker = current;
    current = current->next;
    delete this->worker;
    
  }
  this->head = NULL;
}

template <class T>
LnkdLst::Node* LnkdLst::first(){
  return this->head;
}

template <class T>
LnkdLst::Node* LnkdLst::last(){
  Node* last = this->head;
  while (last->next!=NULL){
   last = last->next;
  }
  return last;
}

template <class T>
void LnkdLst::extract(int index){
  Node* temp;
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