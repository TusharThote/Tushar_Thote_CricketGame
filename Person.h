#ifndef _PERSON_H_
#define _PERSON_H_

#pragma once
#include <string>

class Person{
    protected:
        std::string PersonName;
    public:
        Person();
        Person(std::string name);
        std::string GetPersonName();
};

#endif