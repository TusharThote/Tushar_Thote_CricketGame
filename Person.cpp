#include <iostream>
#include "Person.h"

Person::Person():Person("Unknown"){}

Person::Person(std::string name):PersonName{name}{}

std::string Person::GetPersonName()
{
    return PersonName;
}
