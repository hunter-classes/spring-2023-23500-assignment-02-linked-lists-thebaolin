#include <iostream>
#include "OList.h"
#include "node.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        delete current;
        current = next;
    }

    head = nullptr;
}


void OList::insert(std::string data) {
    Node *newNode = new Node(data);
    if (head == nullptr || data < head->getData()) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node *trailer = head;
        Node *walker = head->getNext();
        while (walker != nullptr && data >= walker->getData()) {
            trailer = walker;
            walker = walker->getNext();
        }
        trailer->setNext(newNode);
        newNode->setNext(walker);
    }
}

bool OList::contains(std::string item){
    Node *walker = head;

    while(walker != nullptr){
        if(walker->getData() == item){
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

std::string OList::get(int loc){
    Node *walker = head;
    int pos = 0;

    while(walker != nullptr){
        if(pos == loc){
            return walker->getData();
        }
        pos++;
        walker = walker->getNext();
    }

    return "";
}

void OList::remove(int loc){

    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr; // one behind

    while(loc>0 && walker != nullptr){
        loc--;
        trailer=walker;
        walker = walker->getNext();
    }

    if (walker == nullptr) {
    throw std::out_of_range("Index out of bounds");
    }

    //means that the node being removed is the first node, so update head
    if (trailer == nullptr) {
        head = walker->getNext();
    } else {
        trailer->setNext(walker->getNext());
    }
    delete walker;
    
}

void OList::reverse(){
    Node *curr = head;
    Node *walker = nullptr; Node *trailer = nullptr;

    while(curr != nullptr){
        walker = curr->getNext();
        curr->setNext(trailer);
        trailer = curr;
        curr = walker;
    }
    head = trailer;
}


int OList::length(){
  int count = 0;
  Node *walker = head;
  while (walker != nullptr){
    count++;
    walker = walker->getNext();
  }
  return count;
}

std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + " --> ";
    tmp = tmp->getNext();
  }
  result = "head --> " + result + "nullptr";
  return result;
}