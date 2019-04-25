#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//#define N 5
#define ROW 3
#define COL 3
#define MAX 6

float area(float x, float y);
char Aa(char ch);
void main()
{
    //播放音乐
//    PlaySound(TEXT("sounds\\music.mp3"),
//              NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);

//    float x,y;
//    char str[10];
//    char ch;
//
//    printf("请输入x =\n");
//    scanf("%f",&x);
//    printf("请输入y =\n");
//    scanf("%f",&y);
//    printf("请输入你的名字\n");
//    scanf("%s",&str);
//
//    float c = area(x,y);
//
//    printf("长方形面积%d, 我的名字是%s\n",c,str);
//    printf("长方形面积%.3f\n",c);
//
//    printf("请输入需要转换大小写的字母\n");
//    scanf("%s",&ch);
//    char num = Aa(ch);
//    printf("%c\n",num);

//**************************************************************

//冒泡算法
//    int i=0;
//    int j=0;
//    int cup[N];
//    for(i=0; i<N; i++)
//    {
//        scanf("%d",&cup[i]);
//    }
//
//    for(int i=0; i<N-1; i++)
//    {
//        for(j=0; j<N-i-1; j++)
//        {
//            if(cup[j] < cup[j+1])
//            {
//                int temp = cup[j];
//                cup[j] = cup[j+1];
//                cup[j+1] = temp;
//
//            }
//
//        }
//
//        for(int k=0; k<N; k++)
//        {
//            printf("%d\t",cup[k]);
//
//        }
//        printf("\n");
//
//    }

//    for(i=0; i<N; i++)
//    {
//        printf("%d\t",cup[i]);
//    }
//**************************************************************



//删除数组
//    int i=0;
//    int j=0;
//    int s=0;
//    int count = 5;
//    int cup[count];
//    int del;
//    int insertNum;
//    for(i=0; i<count; i++)
//    {
//        scanf("%d",&cup[i]);
//    }
//
//    for(i=0; i<count; i++)
//    {
//        printf("%d\t",cup[i]);
//    }
//    printf("\n请输入要删除的值\n");
//
//    scanf("%d",&del);
//
//    for(int i=0; i<count; i++)
//    {
//        if(cup[i] == del)
//        {
//            for(j=i; j<count-1; j++)
//            {
//                cup[j] = cup[j+1];
//            }
//            s=1;
//            break;
//        }
//
//    }
//
//    for(i=0; i<count-s; i++)
//    {
//        printf("%d\t",cup[i]);
//    }
//
//    printf("\n在数组中插入一个数字\n");
//    scanf("%d",&insertNum);
//    cup[count-1] = insertNum;
//     for(i=0; i<count; i++)
//    {
//        printf("%d\t",cup[i]);
//    }

//二维数组
//    double score[ROW][COL];
//    int i,j;
//    for(i=0; i<ROW; i++)
//    {
//
//        for(j=0; j<COL; j++)
//        {
//            printf("第%d位同学第%d门课成绩",i+1,j+1);
//            scanf("%lf",&score[i][j]);
//        }
//    }
//
//     printf("语文\t数学\t英语\n");
//    for(i=0; i<ROW; i++)
//    {
//
//        for(j=0; j<COL; j++)
//        {
//            printf("%-6.2lf\t",score[i][j]); // %-6表示左对齐及位数
//        }
//        printf("\n");
//    }


//趣味小游戏

//使用字符数组表示字符串
    int i;
    int count=5; //当前未打入冷宫的嫔妃个数
    int searchIndex = -1; //用来存放查找 到元素的下标
    char emperorName[50];
    int choice;   //皇帝的选择1-4之间
    char tempName[20]; //用来存放临时字符串的字符数组
    char names[MAX][20] = {"貂蝉","杨玉环","不知火舞","西施","蒙小兰"};
    //宾妃的级别数组
    char levelNames[5][20] = {"费人","宾妃","贵妃","皇贵妃","皇后"};
    //用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
    int levels[MAX] = {1,2,0,0,0,-1};
    //loves数组中每个元素对应每个妃子的好感度，初始情况，
    //每个人的好感度都为100
    int loves[MAX] = {100,100,100,100,100,-1};

    printf("看当前嫔妃的状态\n\n");
    printf("%-12s\t级别\t好感度\n","姓名");
    for(i=0; i<count; i++)
    {
        printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }

    printf("\n请输入当前皇帝的名号：");
    scanf("%s",emperorName); //录入字符串,不需要&
    printf("\n皇帝《%s》驾临，有事上奏，无事退朝！\n\n",emperorName);
    printf("1、皇帝下旨选妃\t\t(新增功能)\n");
    printf("2、翻牌宠幸！\t\t(修改状态功能)\n");
    printf("3、打入冷宫！\t\t(删除功能)\n");
    printf("4、单独召见爱妃去小树林做纯洁的事。\n\n");
    printf("陛下请选择: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://增加数组元素(names，loves，levels)
        //增加前需要判断数组有没有空间
        printf("\n1、皇帝下旨选妃\t\t(新增功能)\n\n");

        if(count < MAX) //如果当前的妃子数量小于系统最大值
        {
            printf("请输入娘娘的名讳: ");
            scanf("%s",names[count]);
            //将第count个元素的状态初始化
            levels[count] = 0; //级别初始化
            loves[count] = 100; //好感度初始化
            count++;  //添加完元素后，记得增加计数器

            printf("***********************************************\n");
            printf("当前嫔妃的状态\n\n");
            printf("%-12s\t级别\t好感度\n","姓名");
            for(i=0; i<count; i++)
            {
                printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
            printf("\n***********************************************\n");

        }
        else
        {
            printf("陛下，要注意龙体啊，后宫已经人满为患！\n添加失败！\n");
        }

        break;
    case 2:
        printf("2、翻牌宠幸！\t\t(修改状态功能)\n");
        //找到要宠幸妃子的下标
        //修改这个妃子的状态 好感度+10 级别升1级  如果最高级别就不再升级
        //修改其他妃子的状态 由于羡慕嫉妒恨 其他妃子好感度-10
        printf("陛下，请输入今天要翻牌娘娘的名讳: ");
        scanf("%s",tempName);
        //字符串的查找strcmp 需要引入<string.h>
        //strcmp(tempName,"xxx")  0-两个字符串相等 1 前一个大于后一个  -1后一个大于前一个
        for(i=0; i<count; i++)
        {
            if(strcmp(tempName,names[i]) == 0) //如果输入的姓名刚好等于数组某个人的姓名
            {
                loves[i] += 10;
                //级别要注意，不能超过5级（0-4之间）
                levels[i] = levels[i]>=4?4:levels[i]+1;
            }
            else
            {
                loves[i] -= 10;

            }
        }
        printf("***********************************************\n");
        printf("当前嫔妃的状态\n\n");
        printf("%-12s\t级别\t好感度\n","姓名");
        for(i=0; i<count; i++)
        {
            printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("\n***********************************************\n");

        break;
    case 3:
        //1、查找
        //2、 后面一个赋值给前面一个元素
        //3、总数--
        //修改其他人的状态
        printf("3、打入冷宫！\t\t(删除功能)\n\n");
        printf("陛下，请输入打入冷宫的姓名: ");
        scanf("%s",tempName);
        //循环查找
        for(i=0; i < count; i++)
        {
            if(strcmp(tempName,names[i]) == 0) //比较字符串是否相等
            {
                //记录下查找到的下标
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex) //如果searchIndex值为-1，表示没找到
        {
          printf("虚惊一场，没人打入冷宫，该吃吃该喝喝！\n");
        }else
        {
            for(i=searchIndex;i<count;i++){
                //name[i] = name[i+1] 不成立：C语言中不支持数组赋值给数组
             //我们需要使用strcpy函数实现数组赋值
             strcpy(names[i],names[i+1]);
             loves[i] = loves[i+1];
             levels[i] = levels[i+1];
             }
             count--;

             //其他妃子好感度+20
             for(i=0;i<count;i++){
              loves[i] += 20;
             }

        }

       printf("***********************************************\n");
        printf("当前嫔妃的状态\n\n");
        printf("%-12s\t级别\t好感度\n","姓名");
        for(i=0; i<count; i++)
        {
            printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("\n***********************************************\n");

        break;
    case 4:
        printf("4、单独召见爱妃去小树林做纯洁的事。\n");


        break;
    default:
        printf("君无戏言，请陛下再次确认！\n");
    }
//    printf("***********************************************\n");
//    printf("测试代码：查看当前嫔妃的状态\n");
//    printf("%-12s\t级别\t好感度\n","姓名");
//    for(i=0; i<count; i++)
//    {
//        printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
//    }
//    printf("***********************************************\n");


}



//*******************************************************************



//计算长方形的面积
float area(float x, float y)
{
    return x * y;

}

//大小写转换
char Aa(char ch)
{
    int num = (int)ch;
    if(num < 97)
    {
        num += 32;
    }
    return (char)num;
}


