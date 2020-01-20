//
// Created by Mike Gao on 2020-01-19.
//

#include "Person.h"
#include <string>
#include <iostream>

Person::Person(std::string first, std::string last, int arbitrary):
FirstName(first), LastName(last), arbitraryNumber(arbitrary)
{
    std::cout << "constructing " << getName() << std::endl;
}

Person::Person() : arbitraryNumber(0)
{
    std::cout << "constructing " << FirstName << " " << LastName << std::endl;
}
Person::~Person()
{
    std::cout << "destructing " << FirstName << " " << LastName << std::endl;
}
std::string Person::getName()
{
    return FirstName + " " + LastName;
}