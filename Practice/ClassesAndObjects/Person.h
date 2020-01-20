//
// Created by Mike Gao on 2020-01-19.
//

#ifndef PRACTICE_PERSON_H
#define PRACTICE_PERSON_H

#include <string>

class Person {
private:
    std::string FirstName;
    std::string LastName;
    int arbitraryNumber;
public:
    Person(std::string first, std::string last, int arbitrary);
    // Person()=default; default constructor
    Person();
    ~Person();
    std::string getName();

};


#endif //PRACTICE_PERSON_H
