#pragma once
#include <iostream>
#include "node.h"

class OList{
 private:
  Node *head;
 public:
  OList();
  ~OList();
  void insert(std::string data);
  void insert(int loc, std::string data); //0 indexed
  bool contains(std::string item);
  void remove(int loc);
  int length();

  std::string toString(); // for testing purposes

  

};