#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/**
 *�˼���
 *copy�Ͼ�game
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "gamelib.h"
/* ��Ϸ��ͼ */
typedef struct _map{
    int id;         //��Ϸ�����
    char name[50];
    int minlevel;
    COORD coord;
    char desc[500];
}map;
typedef enum _proptype{
    Weapon,Armor,Con,card,Frag
}Proptype;
/* ���� */
typedef struct _martial{
    int id;         //���ɱ��
    char name[21];  //��������
    char type[11];  //�������ͣ����ɡ�а�ɡ�������а
    COORD hqCoord;  //�ܲ����꣨X-�У�Y-�У����������������෴
    int isOpen;     //�Ƿ񿪷�
    char description[1000];//��������
}Martial;
typedef struct _prop{
    int id;            //���߱��
    char name[50];     //��������
    int leve;          //���ߵļ���
    int stock;         //���ߵĿ��
    double price;       //�۸�
    Proptype type;      //��������
    union {             //����
    int minAttack;
    int minDefence;
    int minPower;
    };
    union {             //����
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
    Martial martial;//��������
    Prop Weapon;
    Prop Armor;
    COORD coord;
    //��ҵı���
}player;
/*  �������ĺ��� */
typedef struct _monster{
    int id;
    char name[50];
    int level;
    int hp;
    int att;    //���﹥����
    int diff;       //������
    int minmoney;
    int maxmoney;
    int exp;    //ɱ�����һ�õľ���ֵ
    int state;  //���ﵱǰ��״̬
    COORD coord;  //���������
}monster;
void Init();        //��ʼ����Ϸ����
void show();//��ʾȫ������
/*  ��ʾ��Ϸ�Ļ�ӭ��Ϣ*/
void showwelcome();
/*  ��ʾ��Ϸ��ͼ  */
void showmap();
/* ��ʾ��ͼ�ĸ�����Ϣ */
void showmapinfo();
/* ��ʾ��Ϸ��ͼ�·�����Ϣ */
void showinformation();
/* ��ʾ��Ϸ�����˵� */
void showmainmenu();
/* ͨ������������Ϸ���˵� */
void processmainmenu(char key);
/* ��ʾ��ҵĸ������� */
void showplayerinfo();
/* ����Ϣ������ʾ��ǰ��ͼ�Ĺ��� */
void showmonsters();
/* ��ֺ��� */
void fight(monster *monster);
/* ���ܶ� */
void ShowHQ();//���ܲ�
void showattribute();
#endif // GAME_H_INCLUDED
