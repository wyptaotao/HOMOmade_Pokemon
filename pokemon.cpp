#include<cstdio>
#include<QDebug>
#include<time.h>
#include"pokemon.h"
#include"global.h"

pokemon::pokemon(){};
pokemon::pokemon(string n_name){
    type=DFT;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=0;
    def=0;
    hp=0;
    interval=0;
}//构造函数
void pokemon::level_up(){
    while(exp>=MAX_EXP){
        if(level==MAX_LEVEL){
            exp=0;
            break;
        }//若满级则不再升级
        level++;//等级上升
        exp=exp-MAX_EXP;//溢出经验值
        qDebug()<<QString::fromStdString(name)<<"升到了"<<level<<"级！";
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
            interval*=0.7;
        }
        //属性上升
    }//升级到经验花光
}//升级
void pokemon::death(){
    status=DEAD;//置状态为死亡
    qDebug()<<QString::fromStdString(name)<<"死了！";
}//死亡
void pokemon::take_damage(int damage){
    int doc=rand()%100+1;//dodge or critical，生成一个1-100之间的随机数
    qDebug()<<"看看摇点："<<doc;
    if(doc<=10)/*10%的几率闪避*/{
        qDebug()<<QString::fromStdString(name)<<"闪避了这次攻击，没有受伤！";
        return;//结束受伤函数
    }//闪避事件
    if(doc>=90)/*10%的几率暴击*/{
        qDebug()<<"这次攻击发生了暴击！";
        damage*=2;//伤害增加为二倍
    }//暴击事件
    int r_damage=damage-def;//受到伤害为实际伤害值减去防御力
    qDebug()<<QString::fromStdString(name)<<"受到了"<<damage<<"点攻击力的攻击，经过防御后受到了"<<r_damage<<"点伤害！";
    if(r_damage>=hp){
        hp=0;//hp归零
        death();//死亡
    }//受伤死亡
    else{
        hp-=r_damage;
        qDebug()<<QString::fromStdString(name)<<"吃下了攻击，还剩"<<hp<<"点生命值！";
    }//受伤掉血
}//受伤
void pokemon::gain_exp(int expp){
    exp+=expp;
    qDebug()<<QString::fromStdString(name)<<"获得了"<<expp<<"点经验值！";
    if(level==15){
        exp=0;
    }//如满级则不再升级
    else{
        level_up();
    }//未满级则升级
}//获得经验
int pokemon::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了普通攻击！造成了"<<atk<<"点伤害！";
    return atk;
}//虚函数 攻击

/*----------pokemon类----------*/


Charmander::Charmander(){
        type=STR;
        status=ALIVE;
        name="小火龙";//默认名称
        level=INIT_LEVEL;
        exp=0;
        atk=7;
        def=2;
        hp=10;
        interval=1;
}
Charmander::Charmander(string n_name){
        type=STR;
        status=ALIVE;
        name=n_name;//起名
        level=INIT_LEVEL;
        exp=0;
        atk=7;
        def=2;
        hp=10;
        interval=1;
}
int Charmander::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了火花！造成了"<<atk<<"点伤害！";
    return atk;
}//小火龙 攻击

/*----------Charmander类----------*/


Geodude::Geodude(){
    type=STR;
    status=ALIVE;
    name="小拳石";
    level=INIT_LEVEL;
    exp=0;
    atk=8;
    def=2;
    hp=10;
    interval=1;
}
Geodude::Geodude(string n_name){
    type=STR;
    status=ALIVE;
    name=n_name;//起名
    level=INIT_LEVEL;
    exp=0;
    atk=8;
    def=2;
    hp=10;
    interval=1;
}
int Geodude::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了落石！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Geodude类----------*/


Bulbasaur::Bulbasaur(){
    type=SHD;
    status=ALIVE;
    name="妙蛙种子";
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=2;
    hp=15;
    interval=1;
}
Bulbasaur::Bulbasaur(string n_name){
    type=SHD;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=2;
    hp=15;
    interval=1;
}
int Bulbasaur::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了藤鞭！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Bulbasaur类----------*/


Squirtle::Squirtle(){
    type=SHD;
    status=ALIVE;
    name="杰尼龟";
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=1;
    hp=18;
    interval=1;
}
Squirtle::Squirtle(string n_name){
    type=SHD;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=1;
    hp=18;
    interval=1;
}
int Squirtle::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了水枪！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Squirtle类----------*/


Metapod::Metapod(){
    type=DEF;
    status=ALIVE;
    name="铁甲蛹";
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=3;
    hp=12;
    interval=1;
}
Metapod::Metapod(string n_name){
    type=DEF;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=3;
    hp=12;
    interval=1;
}
int Metapod::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了撞击！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Metapod类----------*/


Shellder::Shellder(){
    type=DEF;
    status=ALIVE;
    name="大舌贝";
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=4;
    hp=10;
    interval=1;
}
Shellder::Shellder(string n_name){
    type=DEF;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=4;
    hp=10;
    interval=1;
}
int Shellder::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了贝壳刃！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Shellder类----------*/


Pikachu::Pikachu(){
    type=SPD;
    status=ALIVE;
    name="皮卡丘";
    level=INIT_LEVEL;
    exp=0;
    atk=6;
    def=2;
    hp=10;
    interval=0.9;
}
Pikachu::Pikachu(string n_name){
    type=SPD;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=6;
    def=2;
    hp=10;
    interval=0.9;
}
int Pikachu::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了电光一闪！造成了"<<atk<<"点伤害！";
    return atk;
}

/*----------Pikachu类----------*/


Meowth::Meowth(){
    type=SPD;
    status=ALIVE;
    name="喵喵";
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=2;
    hp=10;
    interval=0.8;
}
Meowth::Meowth(string n_name){
    type=SPD;
    status=ALIVE;
    name=n_name;
    level=INIT_LEVEL;
    exp=0;
    atk=5;
    def=2;
    hp=10;
    interval=0.8;
}
int Meowth::attack(){
    qDebug()<<QString::fromStdString(name)<<"使用了疯狂乱抓！造成了"<<atk<<"点伤害！";
    return atk;
}




