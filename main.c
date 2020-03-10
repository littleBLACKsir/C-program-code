#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gamelib.h"
#include "game.h"
//假设当前用户的坐标为3，2
extern int X,Y;
int main()
{  char key;//用户按键
   settitle("The copy_game made by littleBLACKsir(小邓)");
   setcolor(10,0);
   Init();          //初始化游戏数据
   showwelcome();
   showmap();
   showinformation();
   showmainmenu();
   while(1)
   {   fflush(stdin);
       key=getch();//持续接收用户输入
       fflush(stdin);//清空缓存区，其实加不加都没事，为了规范标准
       if(key == '1' ||key == '2' ||key == '3' ||key == '4' ||key == '5' ){
         processmainmenu(key);
         continue;
       }
       else if(key == VK_UP || key ==72)
       {
            Y--;
       }
       else if(key == 39 || key ==77)
       {
            X++;
       }
       else if(key == 40 || key == 80)
       {
            Y++;
       }
       else if(key == 37 || key == 75)
       {
            X--;
       }
       if(X>7) X=0;
       if(X<0) X=7;
       if(Y>7) Y=0;
       if(Y<0) Y=7;
       showmap();
   }
    return 0;
}
