#include "mainwindow.h"
#include "pokemon.h"
#include <QApplication>

const int MAX_LEVEL=15;//等级最大值为15
const int INIT_LEVEL=1;//初始等级为1
const int MAX_EXP=100;//每一百点经验值升级一次

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
