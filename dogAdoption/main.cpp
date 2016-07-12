#include "mainwindow.h"
#include <QTableView>
#include "assert.h"
#include <string.h>
#include <QApplication>
#include <Windows.h>

#include "controller.h"
#include "dogstablemodel.h"
#include "dogsqtui.h"
using namespace std;

void testDog();
void testRepo();
void testAdoptionList();
void testController();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testDog();
    testRepo();
    testAdoptionList();
    testController();
    repository repo("dogs.txt");
    controller ctrl(repo);
    cout<<"Hello"<<endl;
    DogQtUi qtUI(ctrl);
    cout<<"Hello"<<endl;
    dogstablemodel dogTable(repo);
    QTableView table;
    table.setModel(&dogTable);
    qtUI.show();
//    table.show();

    return a.exec();
}

void testDog() {
    dog d("Maple","c",2,"google.com");
    dog d1("Name","Breed",2,"google.com");
    dog d2,d3;
    assert(d2==d3);
    assert(d.getName()=="Maple");
    assert(d1.getAge()==2);
}

void testRepo() {
    repository repo("dogs.txt");
    dogVector arr;
    dog d("Maple","c",2,"google.com");
    repo.addDog(d);
    assert(repo.getSize() == 6);
    arr = repo.findByBreedAndAge("c",2);
    assert(arr.size() == 1);
    assert(repo.foundDog("Maple","c"));
    repo.removeDog(d);
    assert(repo.getSize() == 5);
}

void testAdoptionList() {
    adoptionlist adopt;
    assert(adopt.getSize() == 0);
}

void testController() {
    repository repo("dogs.txt");
    controller ctrl(repo);
    dog d("Maple","c",2,"google.com");
    ctrl.addDogToRepo("Maple","c",2,"google.com");
    assert(ctrl.getSize() == 6);
    ctrl.removeDogFromRepo(d);
    assert(ctrl.getSize() == 5);
    d.setAdoption(1);
    ctrl.addAdoptionList(d);
    ctrl.remAdoptionList(d);
}
