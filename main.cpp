#include <iostream>
#include "OList.h"

int main(){

OList *l = new OList();

  std::cout<<"insert(1) + insert(3) + insert(2) + insert(5)" << std::endl;

  l->insert("1");
  l->insert("3");
  l->insert("2");
  l->insert("5");

  std::cout << l->toString() << "\n";

  std::cout << "get(2) : " << l->get(2)<< "\n";

  if (l->contains("1")) {
    std::cout << "The list contains '1'\n";
  }

  if (l->contains("6")) {
    std::cout << "The list contains '6'\n";
  }
  else {
    std::cout << "The list does not contain '6'\n";
  }
  l->remove(1);
  std::cout<<"remove(1) : " << l->toString() << "\n";

  l->reverse();
  std::cout << "reverse() : " << l->toString() << "\n";
  l->~OList();
  
  std::cout << "~OList() destructor: " <<  l->toString() << "\n";

  return 0;
}