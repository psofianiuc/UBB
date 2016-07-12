#ifndef QTUI_H
#define QTUI_H

#include <QWidget>

namespace Ui {
class qtui;
}

class qtui : public QWidget
{
    Q_OBJECT

public:
    explicit qtui(QWidget *parent = 0);
    ~qtui();

private:
    Ui::qtui *ui;
};

#endif // QTUI_H
