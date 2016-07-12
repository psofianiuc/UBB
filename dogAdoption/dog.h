#ifndef DOG_H
#define DOG_H

#include <string.h>
#include <iostream>

class dog
{
private:
    std::string name;
    std::string breed;
    int age;
    std::string link;
    int adoption;
public:
    dog(const std::string& n,const std::string& b,const int& a,const std::string& l);
    dog(): name(""), breed (""), age(-1), link(""), adoption(0) {}

    std::string getName() const {return name;}
    std::string getBreed() const {return breed;}
    int getAge() const {return age;}
    std::string getLink() const {return link;}
    int getAdoption() const {return adoption;}

    void setName(std::string const& newName) {name = newName;}
    void setBreed(std::string const& newBreed) {breed = newBreed;}
    void setAge (int const newAge) {age= newAge;}
    void setLink (std::string const& newLink) {link = newLink;}
    void setAdoption(int stat) {adoption = stat;}

    void openLink();
    bool operator==(const dog& d);
};

#endif // DOG_H
