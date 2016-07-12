#pragma once

#include "dog.h"
#include <vector>

typedef std::vector<dog> dogVector;

class adoptionlist
{
private:
    dogVector arr;

public:
    adoptionlist() {}

    void add(const dog& d);
    void rem(const dog& d);

    void setAdoptionList(const dogVector& a);
    dogVector getAdoptionList() const {return arr;}

    int getSize() {return (int)arr.size();}
};

