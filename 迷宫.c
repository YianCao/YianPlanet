//  走迷宫程序，共有2种难度
#include <stdio.h>
#include <stdlib.h>

//通过控制台进行数据输入和输出的函数，主要是通过键盘进行的操作，如getch()
#include <conio.h>
int s1[10][10]={{1,1,1,1,1,3,1,1,1,1},
                {1,0,0,0,1,0,0,0,0,1},
                {1,0,1,0,0,1,1,1,0,1},
                {1,0,1,0,0,1,0,0,0,1},
                {1,0,0,1,0,0,1,0,1,1},
                {1,1,0,0,1,0,1,0,0,1},
                {1,0,0,1,0,0,0,0,1,1},
                {1,1,0,1,1,1,0,0,1,1},
                {1,0,0,0,1,0,1,0,1,1},
                {1,1,1,2,1,1,1,1,1,1}};


int s2[20][20]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		        {3,0,0,0,1,1,0,0,0,1,0,0,1,1,1,0,0,0,1,1},
		        {1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
		        {1,1,0,1,0,1,0,1,1,0,1,1,1,1,0,1,0,0,1,1},
		        {1,0,0,0,1,1,0,1,0,0,0,1,0,1,1,0,1,0,0,1},
		        {1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1},
		        {1,0,1,1,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1},
		        {1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,1,1,0,1,1},
		        {1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,0,1},
		        {1,0,0,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,1},
		        {1,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,1,1,1},
		        {1,0,0,0,1,1,0,0,1,0,1,1,0,1,1,0,0,1,0,1},
		        {1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1},
		        {1,0,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1},
                {1,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1},
		        {1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,1},
	            {1,1,0,1,1,1,0,1,0,1,1,1,1,0,0,0,0,0,0,1},
		        {1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,1,1},
	            {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,2},
		        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int s3[30][30]={{1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,1},
                {1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1},
                {1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1},
                {1,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1},
                {1,0,0,0,0,1,1,0,1,0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,0,0,1},
                {1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,1},
                {1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
                {1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1},
                {1,1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1},
                {1,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,0,1},
                {1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,0,1,1},
                {1,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1},
                {1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1},
                {1,0,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1},
                {1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,0,0,0,0,0,1,1,0,1,1,1,0,1},
                {1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
                {1,1,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,0,0,0,1,0,1},
                {1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1},
                {1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,1},
                {1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1},
                {1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,1},
                {1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,0,1},
                {1,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,3},
                {1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

//迷宫画图函数
void draw1(void);
void draw2(void);
void draw3(void);

//控制函数
void control1(void);
void control2(void);
void control3(void);

//菜单函数
void menu(void);

//移动后位置交换函数
void move(int *i,int *j);

//主函数
int main()
{
    menu();
    system("pause");
    return 0;
}

//菜单函数
void menu(void)
{
    int x;
   printf("***********      欢迎使用迷宫求解          ********\n");
   printf("**************made by Cao Wanying******************\n");
   printf("***************     游戏说明    *******************\n");
   printf("***************************************************\n");
   printf("********** 使用方向键使小人移动，走出迷宫。 ********\n");
   printf("******** 游戏过程中，按Esc键返回游戏菜单;***********\n");
   printf("**************也可以按0直接退出游戏。***************\n");
   printf("*******************1: 开始游戏**********************\n");
   printf("*******************0: 退出游戏**********************\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1: { system("cls");
                  printf("难度选择\n");
                  printf("*****1.简单难度*****\n");
                  printf("*****2.中等难度*****\n");
                  printf("*****3.复杂难度*****\n");
                  printf("*****0.退出游戏*****\n");
                  int y;
                  scanf("%d",&y);
                  switch (y)
                  {
                        case 1:system("cls");
                               draw1();
                               control1();    break;
                        case 2:system("cls");
                               draw2();
                               control2();    break;
                        case 3:system("cls");
                               draw3();
                               control3();    break;
                        case 0:exit(0);
                  }
                }break;
        case 0:exit(0);
      }
}

//移动后位置交换函数
void move(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

void draw1(void)
{
    int i,j,ch,num=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
        {
            ch=s1[i][j];
            switch (ch)
            {
                case 0:printf("  "); break;
                case 1:printf("口"); break;
                case 2:printf("◎"); break;
                case 3:printf("  "); break;
            }
            num++;
            if(num%10==0)
                printf("\n");
        }
    }

void draw2(void)
{
    int i,j,ch,num=0;
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
        {
            ch=s2[i][j];
            switch (ch)
            {
                case 0:printf("  "); break;
                case 1:printf("口"); break;
                case 2:printf("◎"); break;
                case 3:printf("  "); break;
            }
            num++;
            if(num%20==0)
                printf("\n");
        }
}

void draw3(void)
{
    int i,j,ch,num=0;
    for(i=0;i<30;i++)
        for(j=0;j<30;j++)
        {
            ch=s3[i][j];
            switch (ch)
            {
                case 0:printf("  "); break;
                case 1:printf("口"); break;
                case 2:printf("◎"); break;
                case 3:printf("  "); break;
            }
            num++;
            if(num%30==0)
                printf("\n");
        }
}

void control1(void)
{
    int a,b;
    char num;
    do{  //每一次移动前找到小人的位置
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                if(s1[i][j]==2)
                {
                    a=i;
                    b=j;
                    break;
                }
        //接收控制
        num=getch();
        switch(num)
        {
            case 72:if(s1[a-1][b]!=1)  //向上
			        {
				        move(&s1[a][b],&s1[a-1][b]);
				        system("cls");
				        draw1();
				        break;
			        }
			        else continue;
	        case 80:if(a==9) continue; //向下，如果小人站在起点处，不能使用向下键
                    else if(s1[a+1][b]!=1)
			        {
			   	        move(&s1[a][b],&s1[a+1][b]);
				        system("cls");
			            draw1();
			            break;
			        }
			        else continue;

		    case 75:if(s1[a][b-1]!=1) //向左
			        {
				        move(&s1[a][b],&s1[a][b-1]);
				        system("cls");
				        draw1();
			            break;
			        }
			        else continue;
			case 77:if(s1[a][b+1]!=1) //向右
			        {
				        move(&s1[a][b],&s1[a][b+1]);
				        system("cls");
                        draw1();
		                break;
			        }
			        else continue;
		    case 27:system("cls"); //ESE返回菜单
				    menu();    break;
            case 48:exit(0); //退出游戏
		    default:continue;
	    }
		if(s1[0][5]==2)   //到达终点
		{
            printf("\n\t------------------you are winner!--------------------\n\n\n");
            s1[0][5]=3;  //重置起点及终点
            s1[9][3]=2;
		    menu();
	    }
    }while(1);
}

void control2(void)
{
    int a,b;
    char num;
    do{  //每一次移动前找到小人的位置
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++)
                if(s2[i][j]==2)
                {
                    a=i;
                    b=j;
                    break;
                }
        //接收控制
        num=getch();
        switch(num)
        {
            case 72:if(s2[a-1][b]!=1)  //向上
			        {
				        move(&s2[a][b],&s2[a-1][b]);
				        system("cls");
				        draw2();
				        break;
			        }
			        else continue;
	        case 80:if(s2[a+1][b]!=1)//向下
			        {
			   	        move(&s2[a][b],&s2[a+1][b]);
				        system("cls");
			            draw2();
			            break;
			        }
			        else continue;

		    case 75:if(s2[a][b-1]!=1) //向左
			        {
				        move(&s2[a][b],&s2[a][b-1]);
				        system("cls");
				        draw2();
			            break;
			        }
			        else continue;
			case 77:if(b==19) continue;//向右，小人不能走出地图
                    else if(s2[a][b+1]!=1)
			        {
				        move(&s2[a][b],&s2[a][b+1]);
				        system("cls");
                        draw2();
		                break;
			        }
			        else continue;
		    case 27:system("cls"); //ESE返回菜单
				    menu();    break;
            case 48:exit(0); //退出游戏
		    default:continue;
	    }
		if(s2[1][0]==2)   //到达终点
		{
            printf("\n\t------------------you are great!--------------------\n\n\n");
            s2[1][0]=3;  //重置起点及终点
            s2[18][19]=2;
		    menu();
	    }
    }while(1);
}

void control3(void)
{
    int a,b;
    char num;
    do{  //每一次移动前找到小人的位置
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
                if(s3[i][j]==2)
                {
                    a=i;
                    b=j;
                    break;
                }
        //接收控制
        num=getch();
        switch(num)
        {
            case 72:if(a==0) continue;
                    else if(s3[a-1][b]!=1)  //向上
			        {
				        move(&s3[a][b],&s3[a-1][b]);
				        system("cls");
				        draw3();
				        break;
			        }
			        else continue;
	        case 80:if(s3[a+1][b]!=1)//向下
			        {
			   	        move(&s3[a][b],&s3[a+1][b]);
				        system("cls");
			            draw3();
			            break;
			        }
			        else continue;

		    case 75:if(s3[a][b-1]!=1) //向左
			        {
				        move(&s3[a][b],&s3[a][b-1]);
				        system("cls");
				        draw3();
			            break;
			        }
			        else continue;
			case 77:if(s3[a][b+1]!=1)
			        {
				        move(&s3[a][b],&s3[a][b+1]);
				        system("cls");
                        draw3();
		                break;
			        }
			        else continue;
		    case 27:system("cls"); //ESE返回菜单
				    menu();    break;
            case 48:exit(0); //退出游戏
		    default:continue;
	    }
		if(s3[23][29]==2)   //到达终点
		{
            printf("\n\t------------------you are great!--------------------\n\n\n");
            s3[23][29]=3;  //重置起点及终点
            s3[0][1]=2;
		    menu();
	    }
    }while(1);
}

