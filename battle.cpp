#include<QDebug>
#include"pokemon.h"
#include"battle.h"
#include"global.h"

battle::battle(pokemon *C,pokemon *D){
    A=C;
    B=D;
    start();
}
void battle::start(){
    qDebug()<<QString::fromStdString(A->name)<<"和"<<QString::fromStdString(B->name)<<"的战斗开始了！";
    now=FIGHTING;
}
void battle::user_attack(){
    srand(time(NULL));//设置本次攻击的随机数种子
    B->take_damage(A->attack());//用户精灵 攻击
    qDebug()<<"打了打了";
}
void battle::server_attack(){
    srand(time(NULL));//设置本次攻击的随机数种子
    A->take_damage(B->attack());//系统精灵 攻击
    qDebug()<<"还手了还手了";
}
