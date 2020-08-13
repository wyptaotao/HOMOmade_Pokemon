#ifndef POKEMON_H
#define POKEMON_H
#include<iostream>
#include<string>
using namespace std;

const int MAX_LEVEL=15;//等级最大值为15
const int INIT_LEVEL=1;//初始等级为1
const int MAX_EXP=100;//每一百点经验值升级一次

enum TYPE{
    STR=1,//力量型，为1
    SHD,//肉盾型，为2
    DEF,//防御型，为3
    SPD//敏捷型，为4
};//属性枚举

enum STATUS{
    ALIVE=1,//存活
    DEAD//死亡
};//精灵状态

class pokemon{
protected:
    TYPE type;//精灵属性
    STATUS status;//精灵状态
    string name;//精灵名称
    int level=INIT_LEVEL;//精灵等级，初始化
    double exp;//精灵经验值
    int atk;//精灵攻击力
    int def;//精灵防御力
    int hp;//精灵生命值
    double interval;//精灵攻击间隔
public:
    void level_up(){
        level++;//等级上升
        exp=exp-MAX_EXP;//溢出经验值
        if(type==STR){
            atk+=2;
            def+=1;
            hp+=1;
            interval*=0.9;
        }
        else if(type==DEF){
            atk+=1;
            def+=2;
            hp+=1;
            interval*=0.9;
        }
        else if(type==SHD){
            atk+=1;
            def+=1;
            hp+=2;
            interval*=0.9;
        }
        else if(type==STR){
            atk+=1;
            def+=1;
            hp+=1;
            interval*=0.8;
        }
        //属性上升
    }//升级
    void death(){
        status=DEAD;//置状态为死亡
    }//死亡
    void take_damage(int damage){
        int r_damage=damage-def;//受到伤害为实际伤害值减去防御力
        if(r_damage>=hp){
            hp=0;//hp归零
            death();//死亡
        }//受伤死亡
        else{
            hp-=r_damage;
        }//受伤掉血
    }//受伤
    void gain_exp(int expp){
        exp+=expp;
        if(level==15){
            exp=MAX_EXP;
        }//如满级则不再升级
        else{
            level_up();
        }//未满级则升级
    }//获得经验
    virtual int attack(){

    }
};


#endif // POKEMON_H
