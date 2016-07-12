#pragma once
#include <QtWidgets/QMainWindow>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "controller.h"
#include "adoptionList.h"

class DogQtUi : public QWidget
{
    Q_OBJECT

public:
    DogQtUi(controller& c, QWidget *parent =0);
    ~DogQtUi();

private:

    controller ctrl;
    dogVector dogsInRepo;
    dogVector dogsInAdoptionList;

    QListWidget* repoList;
    QListWidget* adoptList;
    QLineEdit* nameEdit;
    QLineEdit* breedEdit;
    QLineEdit* ageEdit;
    QLineEdit* sourceEdit;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* moveAllDogsButton;
    QPushButton* moveOneDogButton;
    QPushButton* showDog;

    QListWidget* Album;

    void initGUI();
    void populateRepoList();
    void populateAlbum();
    int getRepoListSelectedIndex();

    void connectSignalsAndSlots();

private slots:
    // When an item in the list is clicked, the text boxes get filled with the item's information
    void listItemChanged();

    void addDog();
    void deleteDog();
    void updateDog();

    void moveDogToAlbum();
    void moveAllDogsToAlbum();
    void openPhoto();

};

