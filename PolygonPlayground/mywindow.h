#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtWidgets>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>
using namespace std;

#include "glwidget.h"


class MyWindow : public QWidget
{
    Q_OBJECT
public:
    MyWindow();
signals:
    void saveSignal(); //function without codes
    void actionSignal();
    void loadSignal();

public slots:
    void Save();
    void Load();
    void Action();
private:
    QPushButton *exitButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    glWidget *canvas;


};

#endif // MYWINDOW_H