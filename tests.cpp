#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "OList.h"
#include "doctest.h"

OList *l = new OList();

TEST_CASE("Insert + Get"){
    l->insert("2"); 
    CHECK(l->get(0) == "2");
    l->insert("3"); 
    CHECK(l->get(1) == "3");
    l->insert("0"); 
    CHECK(l->get(0) == "0");
    CHECK(l->get(1) == "2");
}

TEST_CASE("Contains"){
    CHECK(l->contains("0") == true);
    CHECK(l->contains("10") == false);
    CHECK(l->contains("2") == true);
    CHECK(l->contains("1") == false);
}

//0,2,3
TEST_CASE("Remove"){
    l->remove(2);
    CHECK(l->get(2) == "");
    l->remove(1);
    CHECK(l->contains("2") == false);
    l->remove(0);
    CHECK(l->contains("0") == false);
    CHECK(l->length() == 0);
}

TEST_CASE("Reverse"){
    l->insert("0"); 
    l->insert("5"); 
    l->insert("3"); 
    l->insert("2");

    //0,2,3,5 -> reverse() -> 5,3,2,0
    l->reverse();
    CHECK(l->get(0) == "5");
    CHECK(l->get(1) == "3");
    CHECK(l->get(2) == "2");
    CHECK(l->get(3) == "0");
}

TEST_CASE("Deconstructor"){
    l->~OList();
    CHECK(l->length() == 0);
    CHECK(l->get(0) == nullptr);
}
