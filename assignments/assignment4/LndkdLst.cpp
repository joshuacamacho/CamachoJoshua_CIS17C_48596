/* 
 * File:   LndkdLst.cpp
 * Author: Joshua Camacho
 * 
 * Created on October 8, 2014, 9:09 AM
 */

#include "LndkdLst.h"
LnkdLst::LnkdLst(int x){
  this->head = new Node;
  this->head->data = x;
  this->head->next = NULL;
  this->worker = this->head;
}

LnkdLst::LnkdLst(const LnkdLst& old){
  this->head = new Node;
  this->worker = new Node;
  this->head->data = old.head->data;
  this->worker = this->head;
  
  while (this->worker != NULL){
    this->worker->next = new Node;
    this->worker = this->worker->next;

  }
  
}
 
void LnkdLst::append(int x){
  this->worker = head;
  while (this->worker->next != NULL){
    this->worker = this->worker->next;
  }
  this->worker->next = new Node;
  this->worker = this->worker->next;
  this->worker->data = x;
  this->worker->next = NULL;
}
 
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

void LnkdLst::prepend(int x){
  Node *before = this->head;
  this->head = NULL;
  this->head = new Node;
  this->head->data = x;
  this->head->next = before;
  before = NULL;
  this->worker = head;
}

void LnkdLst::insertAfter(int index, int x){
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

void LnkdLst::insertBefore(int index, int x){
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

LnkdLst::~LnkdLst(){
  Node* current = head;;
  
  while (current != NULL){
    this->worker = current;
    current = current->next;
    delete this->worker;
    
  }
  this->head = NULL;
}

LnkdLst::Node* LnkdLst::first(){
  return this->head;
}

LnkdLst::Node* LnkdLst::last(){
  Node* last = this->head;
  while (last->next!=NULL){
   last = last->next;
  }
  return last;
}

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