#ifndef BATTLE_H
#define BATTLE_H

#include<QDebug>
#include"pokemon.h"
#include"global.h"

enum battle_status{
    FIGHTING=1,//战斗中
    END//战斗结束
};
enum battle_options{
    ATTACK=1,//攻击
    HEAL,//回血
    RUN//逃跑
};

class battle{
private:
    pokemon* A;//对战精灵A
    pokemon* B;//对战精灵B
    battle_status now;//当前对战状态

public:
    battle(pokemon *C,pokemon *D);
    void start();


};











#endif // BATTLE_H
