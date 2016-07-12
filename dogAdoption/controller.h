#pragma once

#include "repository.h"
#include "adoptionlist.h"

class controller
{
private:
    repository repo;
    adoptionlist adopt;

public:
    controller(const repository& r): repo(r) {}

    repository getRepository() const {return repo;}
    adoptionlist getAdoptionList() const {return adopt;}

    void addDogToRepo(const std::string& n, const std::string& b, const int& a, const std::string& l);
    void removeDogFromRepo(const dog& d);

    void addAdoptionList(const dog& d);
    void remAdoptionList(const dog& d);
    void rewriteAdoptionList();
    void addAllDogsToAdopted();

    int getSize() {return repo.getSize();}
    repository getRepo() {return repo;}
    adoptionlist getAdopted() {return adopt;}

};
