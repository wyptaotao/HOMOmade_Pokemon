#include "mainwindow.h"
#include "pokemon.h"
#include"global.h"
#include <QApplication>
#include<winsock2.h>
#include<windows.h>
#include<ui_mainwindow.h>
#include<QDebug>

const int MAX_LEVEL=15;//等级最大值为15
const int INIT_LEVEL=1;//初始等级为1
const int MAX_EXP=100;//每一百点经验值升级一次


DWORD WINAPI mythread(LPVOID lpParameter){
    struct mypara{
        int a;
        Ui_MainWindow* ui;
    };

    mypara* MY;
    MY=(mypara*)lpParameter;
    qDebug()<<MY->a;

    int flag=1;
    while(1)
        if(flag==0)
            break;
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    struct mypara{
        int a;
        Ui_MainWindow* ui;
    };

    mypara MY;
    MY.a=100;
    MY.ui=w.ui;
    CreateThread(NULL,0,&mythread,&MY,0,NULL);

    return a.exec();
}
