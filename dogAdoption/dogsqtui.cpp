#include "dogsqtui.h"
#include <Windows.h>
#include <sstream>
#include <vector>
#include <QMessageBox>
#include <shellapi.h>
#include <iostream>
#include "dog.h"



DogQtUi::DogQtUi(controller& c, QWidget *parent): ctrl(c), QWidget(parent)
{
    this->initGUI();
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->populateRepoList();
}

DogQtUi::~DogQtUi()
{

}

void DogQtUi::initGUI()
{
    QHBoxLayout* layout = new QHBoxLayout{ this };

    QWidget* leftWidget = new QWidget{};
    QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

    // list
    // set the selection model
    this->adoptList = new QListWidget{};
    this->repoList = new QListWidget{};
    this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);
    QWidget* dogDataWidget = new QWidget{};
    QFormLayout* formLayout = new QFormLayout{ dogDataWidget };
    this->nameEdit = new QLineEdit{};
    this->breedEdit = new QLineEdit{};
    this->ageEdit = new QLineEdit{};
    this->sourceEdit = new QLineEdit{};
    formLayout->addRow("&Name:", nameEdit);
    formLayout->addRow("&Breed:", breedEdit);
    formLayout->addRow("&Age:", ageEdit);
    formLayout->addRow("&Source:", sourceEdit);

    // buttons
    QWidget* buttonsWidget = new QWidget{};
    QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");
    this->showDog = new QPushButton("Open photo");

    gridLayout->addWidget(addButton, 0, 0);
    gridLayout->addWidget(deleteButton, 0, 1);
    gridLayout->addWidget(updateButton, 0, 2);
    gridLayout->addWidget(this->showDog,0,3);

    // add everything to the left layout
    leftSide->addWidget(new QLabel{ "Dogs:" });
    leftSide->addWidget(repoList);
    leftSide->addWidget(dogDataWidget);
    leftSide->addWidget(buttonsWidget);

    // middle component: just two button
    QWidget* middleWidget = new QWidget{};
    QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
    this->moveOneDogButton = new QPushButton{ ">> Move a dog" };
    this->moveAllDogsButton = new QPushButton{ ">> Move all dogs" };
    QWidget* upperPart = new QWidget{};
    QWidget* lowerPart = new QWidget{};
    QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
    vLayoutUpperPart->addWidget(this->moveOneDogButton);
    vLayoutUpperPart->addWidget(this->moveAllDogsButton);
    vLayoutMiddle->addWidget(upperPart);
    vLayoutMiddle->addWidget(lowerPart);

    // right component: the album
    QWidget* rightWidget = new QWidget{};
    QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };


    // one button
    QWidget* albumButtonsWidget = new QWidget{};

    // add everything to the right layout
    rightSide->addWidget(new QLabel{ "Adoption List " });
    rightSide->addWidget(adoptList);
    rightSide->addWidget(albumButtonsWidget);


    // add the three layouts to the main layout
    layout->addWidget(leftWidget);
    layout->addWidget(middleWidget);
    layout->addWidget(rightWidget);

    // connect the signals and slots
    this->connectSignalsAndSlots();
}

void DogQtUi::connectSignalsAndSlots() {
    // add a connection: function listItemChanged() will be called when an item in the list is selected
    QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
    QObject::connect(this->adoptList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

    // add button connections
    QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addDog()));
    QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteDog()));
    QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateDog()));
    QObject::connect(this->moveOneDogButton, SIGNAL(clicked()), this, SLOT(moveDogToAlbum()));
    QObject::connect(this->moveAllDogsButton, SIGNAL(clicked()), this, SLOT(moveAllDogsToAlbum()));
    QObject::connect(this->showDog, SIGNAL(clicked()), this, SLOT(openPhoto()));
}

void DogQtUi::populateRepoList()
{
    if (this->repoList->count() > 0) this->repoList->clear();

    for (auto d : this->dogsInRepo)
    {
        QString itemInList = QString::fromStdString(d.getName() + " - " + d.getBreed());
        this->repoList->addItem(itemInList);
    }

    if (this->dogsInRepo.size() > 0) this->repoList->setCurrentRow(0);
}

void DogQtUi::populateAlbum()
{
    if (this->adoptList->count() > 0) this->adoptList->clear();

    for (auto d : this->dogsInAdoptionList)
    {
        QString itemInList = QString::fromStdString(d.getName() + " - " + d.getBreed());
        this->adoptList->addItem(itemInList);
    }

    if (this->dogsInAdoptionList.size() > 0) this->adoptList->setCurrentRow(0);
}

int DogQtUi::getRepoListSelectedIndex()
{
    if (this->repoList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();

    if (index.size() == 0)
    {
        this->breedEdit->clear();
        this->nameEdit->clear();
        this->ageEdit->clear();
        this->sourceEdit->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}


void DogQtUi::listItemChanged()
{
    int index = this->getRepoListSelectedIndex();
    if (index == -1)
        return;
    dogVector dogs = this->dogsInRepo;

    if(index >= dogs.size()) return;
    dog d = dogs[index];
    int a = d.getAge();
    std::stringstream ss;
    ss << a;
    this->nameEdit->setText(QString::fromStdString(d.getName()));
    this->breedEdit->setText(QString::fromStdString(d.getBreed()));
    this->ageEdit->setText(QString::fromStdString(ss.str()));
    this->sourceEdit->setText(QString::fromStdString(d.getLink()));
}

void DogQtUi::addDog()
{
    std::string name = this->nameEdit->text().toStdString();
    std::string breed = this->breedEdit->text().toStdString();
    int age = this->ageEdit->text().toInt();
    std::string source = this->sourceEdit->text().toStdString();

    this->ctrl.addDogToRepo(name,breed,age,source);
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->populateRepoList();
}

void DogQtUi::deleteDog()
{
    int index = this->getRepoListSelectedIndex();
    if (index == -1)
        return;

    dogVector dogs = this->dogsInRepo;

    if(index >= dogs.size()) return;
    dog d = dogs[index];
    this->ctrl.removeDogFromRepo(d);
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->populateRepoList();
}

void DogQtUi::updateDog()
{
    std::string name = this->nameEdit->text().toStdString();
    std::string breed = this->breedEdit->text().toStdString();
    int age = this->ageEdit->text().toInt();
    std::string source = this->sourceEdit->text().toStdString();

    int index = this->getRepoListSelectedIndex();
    if (index == -1)
        return;

    dogVector dogs = this->dogsInRepo;

    if(index >= dogs.size()) return;
    dog d = dogs[index];

    if(name == "0") name = d.getName();
    if(breed == "0") breed = d.getBreed();
    if(age == 0) age = d.getAge();
    if(source == "0") source = d.getLink();

    this->ctrl.removeDogFromRepo(d);
    this->ctrl.addDogToRepo(name,breed,age,source);
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->populateRepoList();
}

void DogQtUi::moveDogToAlbum()
{
    int index = this->getRepoListSelectedIndex();
    if (index == -1)
        return;

    dogVector dogs = this->dogsInRepo;

    if(index >= dogs.size()) return;
    dog d = dogs[index];

    this->ctrl.addAdoptionList(d);
    this->ctrl.removeDogFromRepo(d);
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->dogsInAdoptionList = this->ctrl.getAdopted().getAdoptionList();
    this->populateAlbum();
    this->populateRepoList();
}

void DogQtUi::moveAllDogsToAlbum()
{
    this->ctrl.addAllDogsToAdopted();
    dogVector aux  = this->dogsInRepo;
    for (auto d : aux)
    {
        this->ctrl.removeDogFromRepo(d);
        this->ctrl.addAdoptionList(d);
    }
    this->dogsInRepo = this->ctrl.getRepo().getDogs();
    this->dogsInAdoptionList = this->ctrl.getAdopted().getAdoptionList();
    this->populateAlbum();
    this->populateRepoList();
}

void DogQtUi::openPhoto()
{
    int index = this->getRepoListSelectedIndex();
    if (index == -1)
        return;

    dogVector dogs = this->dogsInRepo;

    if(index >= dogs.size()) return;
    dog d = dogs[index];

    d.openLink();
    return;
}
