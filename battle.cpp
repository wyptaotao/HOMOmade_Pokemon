#include<QDebug>
#include"pokemon.h"
#include"battle.h"
#include"global.h"

battle::battle(pokemon *C,pokemon *D){
    A=C;
    B=D;
    now=FIGHTING;
    start();
}
void battle::start(){
    qDebug()<<QString::fromStdString(A->name)<<"和"<<QString::fromStdString(B->name)<<"的战斗开始了！";
    srand(time(NULL));//设置本场战斗的随机数种子


}
