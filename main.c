#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gamelib.h"
#include "game.h"
//���赱ǰ�û�������Ϊ3��2
extern int X,Y;
int main()
{  char key;//�û�����
   settitle("The copy_game made by littleBLACKsir(С��)");
   setcolor(10,0);
   Init();          //��ʼ����Ϸ����
   showwelcome();
   showmap();
   showinformation();
   showmainmenu();
   while(1)
   {   fflush(stdin);
       key=getch();//���������û�����
       fflush(stdin);//��ջ���������ʵ�Ӳ��Ӷ�û�£�Ϊ�˹淶��׼
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
