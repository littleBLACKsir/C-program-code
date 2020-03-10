#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

#include <stdio.h>
#include <windows.h>
/* 设置控制后台窗口的标题 */
void settitle(char *title);
/* 设置游戏的前景色和背景色 */
void setcolor(int forecolor,int backcolor);
/* 设置鼠标光标位置 */
void setposition(int x,int y);
/* 定义清空函数 */
void Clear(int x,int y,int rowcount);
#endif // GAMELIB_H_INCLUDED
