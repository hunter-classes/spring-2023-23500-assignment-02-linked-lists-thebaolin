#include <iostream>
#include "list.h"

int main()
{
//   List *l = new List();
//   std::cout << l->toString() << " " << l->length() << "\n";
//   l->insert(0,"a");
//   std::cout << l->toString() << " " << l->length() << "\n";
//   l->insert(0,"b");
//   l->insert(0,"c");
//   l->insert(0,"d");
//   try {
//     l->insert(10,"x");
//   } catch (std::exception e){
//     std::cout << "Insert x didn't work\n";
//   }
//   std::cout << l->toString() << "\n";
//   l->insert(2,"inserted at 2");
//   std::cout << l->toString() << "\n";
//   l->insert(5,"inserted at end");
//   std::cout << l->toString() << " " << l->length() << "\n";

List *l = new List();
  l->insert("a");
  l->insert("b");
  l->insert("c");
  l->insert("d");
  std::cout << l->toString() << "\n";
  
  if (l->contains("b")) {
    std::cout << "The list contains 'b'\n";
  } else {
    std::cout << "The list does not contain 'b'\n";
  }
  
  if (l->contains("x")) {
    std::cout << "The list contains 'x'\n";
  } else {
    std::cout << "The list does not contain 'x'\n";
  }
  return 0;
}