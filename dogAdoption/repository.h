#pragma once

#include<vector>
#include "dog.h"

typedef std::vector<dog> dogVector;

class repository
{
private:
    dogVector dogs;
    std::string fileName;
public:
    repository(const std::string& fN);

    void readFromFile();
    void saveToFile();

    void addDog(const dog& d);
    void removeDog(const dog& d);
    void updateDog(const dog& oldDog, const dog& newDog);

    bool foundDog(const std::string& name, const std::string& breed);
    dogVector findByBreedAndAge(const std::string& breed, int age);

    dogVector getDogs() const {return dogs;}
    int getSize() {return (int)dogs.size();}

};
