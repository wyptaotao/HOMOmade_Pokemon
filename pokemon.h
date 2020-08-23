#ifndef POKEMON_H
#define POKEMON_H
#include<iostream>
#include<string>
using namespace std;



enum TYPE{
    STR=1,//力量型，为1
    SHD,//肉盾型，为2
    DEF,//防御型，为3
    SPD,//敏捷型，为4
    DFT//默认型
};//属性枚举

enum STATUS{
    ALIVE=1,//存活
    DEAD//死亡
};//精灵状态

class pokemon{
public:
    TYPE type;//精灵属性
    STATUS status;//精灵状态
    string name;//精灵名称
    int level;//精灵等级
    double exp;//精灵经验值
    int atk;//精灵攻击力
    int def;//精灵防御力
    int hp;//精灵生命值
    double interval;//精灵攻击间隔

    pokemon();
    pokemon(string n_name);
    void level_up();
    void death();
    void take_damage(int damage);
    void gain_exp(int expp);
    void heal(int hpp);
    virtual int attack();
};

class Charmander:public pokemon{
public:
    Charmander();
    Charmander(string n_name);
    int attack() override;
};//小火龙

class Geodude:public pokemon{
    Geodude();
    Geodude(string n_name);
    int attack() override;
};//小拳石

/*----------力量型宝可梦----------*/


class Bulbasaur:public pokemon{
    Bulbasaur();
    Bulbasaur(string n_name);
    int attack() override;
};//妙蛙种子

class Squirtle:public pokemon{
    Squirtle();
    Squirtle(string n_name);
    int attack() override;
};//杰尼龟

/*----------肉盾型宝可梦----------*/


class Metapod:public pokemon{
    Metapod();
    Metapod(string n_name);
    int attack() override;
};//铁甲蛹

class Shellder:public pokemon{
    Shellder();
    Shellder(string n_name);
    int attack() override;
};//大舌贝

/*----------防御型宝可梦----------*/


class Pikachu:public pokemon{
    Pikachu();
    Pikachu(string n_name);
    int attack() override;
};//皮卡丘

class Meowth:public pokemon{
    Meowth();
    Meowth(string n_name);
    int attack() override;
};//喵喵

/*----------敏捷型宝可梦----------*/



#endif // POKEMON_H
