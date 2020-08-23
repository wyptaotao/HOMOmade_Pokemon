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
    pokemon* A;//对战精灵A，为用户精灵
    pokemon* B;//对战精灵B，为服务器精灵
    battle_status now;//当前对战状态

public:
    battle(pokemon *C,pokemon *D);
    void start();//初始化战斗
    void user_attack();//用户攻击
    void server_attack();//系统攻击


};











#endif // BATTLE_H
