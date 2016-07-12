#include "dog.h"
#include <Windows.h>
#include <assert.h>

dog::dog(const std::string& n, const std::string& b, const int& a, const std::string& l)
{
    this->name = n;
    this->breed = b;
    this->age = a;
    this->link = l;
    this->adoption = 0;
}

void dog::openLink() {
    ShellExecuteA(NULL,NULL,"chrome.exe",link.c_str(), NULL, SW_SHOWMAXIMIZED);
}

bool dog::operator ==(const dog& d) {
    if(age == d.getAge())
        if(breed == d.getBreed())
            return name == d.getName();
    return false;
}

