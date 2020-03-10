#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/**
 *邓家祺
 *copy老九game
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "gamelib.h"
/* 游戏地图 */
typedef struct _map{
    int id;         //游戏的添加
    char name[50];
    int minlevel;
    COORD coord;
    char desc[500];
}map;
typedef enum _proptype{
    Weapon,Armor,Con,card,Frag
}Proptype;
/* 门派 */
typedef struct _martial{
    int id;         //门派编号
    char name[21];  //门派名称
    char type[11];  //门派类型：正派、邪派、亦正亦邪
    COORD hqCoord;  //总部坐标（X-行，Y-列），与正常坐标轴相反
    int isOpen;     //是否开放
    char description[1000];//门派描述
}Martial;
typedef struct _prop{
    int id;            //道具编号
    char name[50];     //道具名称
    int leve;          //道具的级别
    int stock;         //道具的库存
    double price;       //价格
    Proptype type;      //道具类型
    union {             //联合
    int minAttack;
    int minDefence;
    int minPower;
    };
    union {             //联合
    int maxAttack;
    int maxDefence;
    int maxPower;
    };
    char desc[200];
}Prop;
typedef struct _player{
    int id;
    char name[50];
    char pass[50];
    int life;
    int level;
    int exp;
    int hp;
    int mp;
    int mpmax;
    int gold;
    Martial martial;//所属门派
    Prop Weapon;
    Prop Armor;
    COORD coord;
    //玩家的背包
}player;
/*  定义怪物的函数 */
typedef struct _monster{
    int id;
    char name[50];
    int level;
    int hp;
    int att;    //怪物攻击力
    int diff;       //防御力
    int minmoney;
    int maxmoney;
    int exp;    //杀死怪我获得的经验值
    int state;  //怪物当前的状态
    COORD coord;  //怪物的坐标
}monster;
void Init();        //初始化游戏数据
void show();//显示全部数据
/*  显示游戏的欢迎信息*/
void showwelcome();
/*  显示游戏地图  */
void showmap();
/* 显示地图的附带信息 */
void showmapinfo();
/* 显示游戏地图下方的信息 */
void showinformation();
/* 显示游戏的主菜单 */
void showmainmenu();
/* 通过函数处理游戏主菜单 */
void processmainmenu(char key);
/* 显示玩家的个人资料 */
void showplayerinfo();
/* 在信息界面显示当前地图的怪我 */
void showmonsters();
/* 打怪函数 */
void fight(monster *monster);
/* 回总舵 */
void ShowHQ();//回总部
void showattribute();
#endif // GAME_H_INCLUDED
