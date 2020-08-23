#ifndef NET_H
#define NET_H

#include<string>
#include<map>
#include"pokemon.h"
using namespace std;

map<string,string> user_map;//用户哈希表

class user{
private:
    string user_name;//用户名
    pokemon* pokemon_list;//精灵列表

};




#endif // NET_H
