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
    //��������
//    PlaySound(TEXT("sounds\\music.mp3"),
//              NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);

//    float x,y;
//    char str[10];
//    char ch;
//
//    printf("������x =\n");
//    scanf("%f",&x);
//    printf("������y =\n");
//    scanf("%f",&y);
//    printf("�������������\n");
//    scanf("%s",&str);
//
//    float c = area(x,y);
//
//    printf("���������%d, �ҵ�������%s\n",c,str);
//    printf("���������%.3f\n",c);
//
//    printf("��������Ҫת����Сд����ĸ\n");
//    scanf("%s",&ch);
//    char num = Aa(ch);
//    printf("%c\n",num);

//**************************************************************

//ð���㷨
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



//ɾ������
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
//    printf("\n������Ҫɾ����ֵ\n");
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
//    printf("\n�������в���һ������\n");
//    scanf("%d",&insertNum);
//    cup[count-1] = insertNum;
//     for(i=0; i<count; i++)
//    {
//        printf("%d\t",cup[i]);
//    }

//��ά����
//    double score[ROW][COL];
//    int i,j;
//    for(i=0; i<ROW; i++)
//    {
//
//        for(j=0; j<COL; j++)
//        {
//            printf("��%dλͬѧ��%d�ſγɼ�",i+1,j+1);
//            scanf("%lf",&score[i][j]);
//        }
//    }
//
//     printf("����\t��ѧ\tӢ��\n");
//    for(i=0; i<ROW; i++)
//    {
//
//        for(j=0; j<COL; j++)
//        {
//            printf("%-6.2lf\t",score[i][j]); // %-6��ʾ����뼰λ��
//        }
//        printf("\n");
//    }


//ȤζС��Ϸ

//ʹ���ַ������ʾ�ַ���
    int i;
    int count=5; //��ǰδ�����乬����������
    int searchIndex = -1; //������Ų��� ��Ԫ�ص��±�
    char emperorName[50];
    int choice;   //�ʵ۵�ѡ��1-4֮��
    char tempName[20]; //���������ʱ�ַ������ַ�����
    char names[MAX][20] = {"����","����","��֪����","��ʩ","��С��"};
    //�����ļ�������
    char levelNames[5][20] = {"����","����","����","�ʹ���","�ʺ�"};
    //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int levels[MAX] = {1,2,0,0,0,-1};
    //loves������ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ�����
    //ÿ���˵ĺøжȶ�Ϊ100
    int loves[MAX] = {100,100,100,100,100,-1};

    printf("����ǰ������״̬\n\n");
    printf("%-12s\t����\t�øж�\n","����");
    for(i=0; i<count; i++)
    {
        printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
    }

    printf("\n�����뵱ǰ�ʵ۵����ţ�");
    scanf("%s",emperorName); //¼���ַ���,����Ҫ&
    printf("\n�ʵۡ�%s�����٣��������࣬�����˳���\n\n",emperorName);
    printf("1���ʵ���ּѡ��\t\t(��������)\n");
    printf("2�����Ƴ��ң�\t\t(�޸�״̬����)\n");
    printf("3�������乬��\t\t(ɾ������)\n");
    printf("4�������ټ�����ȥС������������¡�\n\n");
    printf("������ѡ��: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1://��������Ԫ��(names��loves��levels)
        //����ǰ��Ҫ�ж�������û�пռ�
        printf("\n1���ʵ���ּѡ��\t\t(��������)\n\n");

        if(count < MAX) //�����ǰ����������С��ϵͳ���ֵ
        {
            printf("���������������: ");
            scanf("%s",names[count]);
            //����count��Ԫ�ص�״̬��ʼ��
            levels[count] = 0; //�����ʼ��
            loves[count] = 100; //�øжȳ�ʼ��
            count++;  //�����Ԫ�غ󣬼ǵ����Ӽ�����

            printf("***********************************************\n");
            printf("��ǰ������״̬\n\n");
            printf("%-12s\t����\t�øж�\n","����");
            for(i=0; i<count; i++)
            {
                printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
            }
            printf("\n***********************************************\n");

        }
        else
        {
            printf("���£�Ҫע�����尡�����Ѿ�����Ϊ����\n���ʧ�ܣ�\n");
        }

        break;
    case 2:
        printf("2�����Ƴ��ң�\t\t(�޸�״̬����)\n");
        //�ҵ�Ҫ�������ӵ��±�
        //�޸�������ӵ�״̬ �øж�+10 ������1��  �����߼���Ͳ�������
        //�޸��������ӵ�״̬ ������Ľ���ʺ� �������Ӻøж�-10
        printf("���£����������Ҫ�������������: ");
        scanf("%s",tempName);
        //�ַ����Ĳ���strcmp ��Ҫ����<string.h>
        //strcmp(tempName,"xxx")  0-�����ַ������ 1 ǰһ�����ں�һ��  -1��һ������ǰһ��
        for(i=0; i<count; i++)
        {
            if(strcmp(tempName,names[i]) == 0) //�������������պõ�������ĳ���˵�����
            {
                loves[i] += 10;
                //����Ҫע�⣬���ܳ���5����0-4֮�䣩
                levels[i] = levels[i]>=4?4:levels[i]+1;
            }
            else
            {
                loves[i] -= 10;

            }
        }
        printf("***********************************************\n");
        printf("��ǰ������״̬\n\n");
        printf("%-12s\t����\t�øж�\n","����");
        for(i=0; i<count; i++)
        {
            printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("\n***********************************************\n");

        break;
    case 3:
        //1������
        //2�� ����һ����ֵ��ǰ��һ��Ԫ��
        //3������--
        //�޸������˵�״̬
        printf("3�������乬��\t\t(ɾ������)\n\n");
        printf("���£�����������乬������: ");
        scanf("%s",tempName);
        //ѭ������
        for(i=0; i < count; i++)
        {
            if(strcmp(tempName,names[i]) == 0) //�Ƚ��ַ����Ƿ����
            {
                //��¼�²��ҵ����±�
                searchIndex = i;
                break;
            }
        }
        if(-1 == searchIndex) //���searchIndexֵΪ-1����ʾû�ҵ�
        {
          printf("�龪һ����û�˴����乬���óԳԸúȺȣ�\n");
        }else
        {
            for(i=searchIndex;i<count;i++){
                //name[i] = name[i+1] ��������C�����в�֧�����鸳ֵ������
             //������Ҫʹ��strcpy����ʵ�����鸳ֵ
             strcpy(names[i],names[i+1]);
             loves[i] = loves[i+1];
             levels[i] = levels[i+1];
             }
             count--;

             //�������Ӻøж�+20
             for(i=0;i<count;i++){
              loves[i] += 20;
             }

        }

       printf("***********************************************\n");
        printf("��ǰ������״̬\n\n");
        printf("%-12s\t����\t�øж�\n","����");
        for(i=0; i<count; i++)
        {
            printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
        }
        printf("\n***********************************************\n");

        break;
    case 4:
        printf("4�������ټ�����ȥС������������¡�\n");


        break;
    default:
        printf("����Ϸ�ԣ�������ٴ�ȷ�ϣ�\n");
    }
//    printf("***********************************************\n");
//    printf("���Դ��룺�鿴��ǰ������״̬\n");
//    printf("%-12s\t����\t�øж�\n","����");
//    for(i=0; i<count; i++)
//    {
//        printf("%-12s\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
//    }
//    printf("***********************************************\n");


}



//*******************************************************************



//���㳤���ε����
float area(float x, float y)
{
    return x * y;

}

//��Сдת��
char Aa(char ch)
{
    int num = (int)ch;
    if(num < 97)
    {
        num += 32;
    }
    return (char)num;
}


