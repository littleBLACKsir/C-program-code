#include "gamelib.h"
void settitle(char *title)
{
    SetConsoleTitle(title);
}
void setcolor(int forecolor,int backcolor)
{
    HANDLE winhandle;       //¾ä±ú
    winhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winhandle,forecolor + backcolor * 0x10);
}
void setposition(int x,int y)
{
     HANDLE winhandle;       //¾ä±ú
     COORD pos = {x,y};
     winhandle = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(winhandle,pos);
}
void Clear(int x,int y,int rowcount)
{
    //每行清除78个空格

    int i,j;
    for(i=0; i < rowcount; i++)
    {
        setposition(x,y + i);
        for(j=0; j< 78; j++)
        {
            printf(" ");        //打印空格，相当于清空
        }
    }

}
