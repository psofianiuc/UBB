#include "adoptionlist.h"

void adoptionlist::add(const dog &d) {
    if(d.getAdoption() == 1) return;
    this->arr.push_back(d);
}

void adoptionlist::rem(const dog &remD) {
    dogVector aux;
    for(unsigned int i = 0;i<arr.size();i++) {
         dog d = arr[i];
         if(!(d==remD)) aux.push_back(d);
     }
    arr = aux;
}

void adoptionlist::setAdoptionList(const dogVector &a) {
    arr = a;
}
