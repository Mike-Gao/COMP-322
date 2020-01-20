//
// Created by Mike Gao on 2020-01-19.
//

#include "Person.h"
#include <string>
#include <iostream>

int main()
{
    Person p1("Mike","Gao",123);
    {
        Person p2;
    } // out of scope for p2
    std::cout << "after innermost block" << std::endl;
    std::string name = p1.getName();
    // Cannot access Arbitrary Number
    // int i = p1.arbitraryNumber;
    return 0;
}

