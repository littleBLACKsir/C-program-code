#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <stdio.h>
#include <windows.h>
/* ���ÿ��ƺ�̨���ڵı��� */
void settitle(char *title);
/* ������Ϸ��ǰ��ɫ�ͱ���ɫ */
void setcolor(int forecolor,int backcolor);
/* ���������λ�� */
void setposition(int x,int y);
/* ������պ��� */
void Clear(int x,int y,int rowcount);
#endif // GAMELIB_H_INCLUDED
