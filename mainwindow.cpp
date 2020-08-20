#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pokemon.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
//    pokemon a("test君");
//    a.attack();
//    a.gain_exp(101);
//    a.take_damage(1919810);
    Charmander b;
    Charmander c("test君二号机");
    b.attack();
    c.attack();
    b.take_damage(c.attack());
    b.take_damage(c.attack());
    b.take_damage(c.attack());

}

MainWindow::~MainWindow()
{
    delete ui;
}

