#include "controller.h"

void controller::addDogToRepo(const std::string &n, const std::string &b, const int &a, const std::string &l){
    dog d(n,b,a,l);
    repo.addDog(d);
}

void controller::removeDogFromRepo(const dog &d){
    repo.removeDog(d);
}

void controller::addAdoptionList(const dog &d) {
    adopt.add(d);
}

void controller::addAllDogsToAdopted(){
    adopt.setAdoptionList(repo.getDogs());
}

void controller::remAdoptionList(const dog &d) {
    adopt.rem(d);
}

void controller::rewriteAdoptionList() {
    dogVector arr = repo.getDogs();
    dogVector aux;
    for(unsigned int i = 0; i < (unsigned int)repo.getSize();i++) {
        if(arr[i].getAdoption() == 1) {
            aux.push_back(arr[i]);
        }
    }
    adopt.setAdoptionList(aux);
}
