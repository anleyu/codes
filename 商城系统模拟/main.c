#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
ģ��ʵ�ֵ��ߵ깺�﹦��(�̵���ʱֻ֧��һ�ֵ���Ʒ)
��Ʒ�߱����� �۸� ��������
ģ����ҹ�����Ϸ����
1 ���ѡ��Ҫ����ĵ���
2 ���ͬ�⽻�׺�۳���Ӧ����Ϸ��
3 ��Ӧ��Ʒ���-1
5 ��ұ�����������Ʒ����Ʒ����+1
*/

//������Ʒ(����)�ṹ
typedef struct _prop
{
    int id; //����Ψһ�ı��
    char name[50];
    double price;
    int stock;  //�����:����ڱ����б�ʾ��������
    char desc[200]; //���ߵĹ�������
} Prop;

//�����ṹ
typedef struct _bag
{
    int payerId;     //������ҵı��
    int count;       //��ǰ�����е��ߵ�����
    int max;         //��ǰ�����еĲ������
    Prop props[8];   //��ǰ�����еĵ�������
} Bag;

//��ҽṹ
typedef struct _player
{
    int id;           //��ұ��
    char name[50];    //�û���/�ǳ�
    char pass[50];    //����
    Bag bag;          //��ҵı���
    double gold;      //��ҽ��-������ʾ:�����ǲ�ͬ��λ
    double sysee;     //Ԫ������ - ���ҵ�λ
} Player;

Prop *props;
Player *players;
int propCount = 0;
int playerCount = 0;


//���ݳ�ʼ��
void Init();
//��ʾ��������
void ShowProps();
//��ʾ�������
void ShowPlayers();
/**
*���׺���
*����1 ���뽻�׵����ָ�� - Ϊ�˷��㽻�׹��̲����������
*����2 ������������Ʒid
*/
void Trade(Player *player,int propId,int propNum);


int main()
{
//��ʼ������
    printf("**************���ݳ�ʼ��**************\n");
    Init();
    printf("**************��Ʒ�б�**************\n");
    ShowProps();
    printf("**************����б�**************\n");
    ShowPlayers();

//ִ�н��״���

//���뽻�ײ���
    int playId;  //��ұ��
    int propId;   //��Ʒ���
    int propNum;  //��������
    char retrade[3];  //�Ƿ��������

    do
    {
        printf("\n��ұ��:");
        scanf("%d",&playId);
        printf("\n��Ʒ���:");
        scanf("%d",&propId);
        printf("\n��������:");
        scanf("%d",&propNum);

        Trade(&players[playId-1],propId,propNum);
        printf("\n**************���Ѻ�**************\n");
        ShowPlayers();
        printf("\n�Ƿ��������y/n:");
        fflush(stdin);
        scanf("%s",retrade);
        fflush(stdin);
    }
    while(strcmp("y",retrade) == 0 || strcmp("Y",retrade) == 0 || strcmp("yes",retrade) == 0 || strcmp("YES",retrade) == 0);

    return 0;
}

void Init()
{
    static Prop propArray[] =
    {
        {1,"˫�����鿨",3000,100,"˫��666"},
        {2,"���õĵ���",5000,8,"ֻ��Զ�۲��ɰ���!"},
        {3,"���������",8000,100,"ˮ����,�˺�����"},
        {4,"ֱ��1����",83000,100,"����֮��ҡͷ����"}
    };

    props = propArray;  //�趨ָ�������
    propCount = sizeof(propArray)/sizeof(Prop);
    static Player playerArry[]=
    {
        {1,"����ëë��","13456",.gold=5000,.bag.max=8},
        {2,"�����ֵ����","13456",.gold=15000,.bag.max=8},
        {3,"��ʴ��","13456",.gold=50000,.bag.max=8},
        {4,"�Ǻ�","13456",.gold=115000,.bag.max=8}
    };
    players = playerArry;
    playerCount = sizeof(playerArry)/sizeof(Player);

}
void ShowProps()
{
    int i;
    if(props == NULL)
        return;
    printf("%-5s%-14s%-8s���\t��Ʒ����\n","���","����","����");
    for(i=0; i<propCount; i++)
    {
        printf("%-5d%-14s%-7.2lf\t%d\t%s\n",props[i].id,props[i].name, props[i].price, props[i].stock,props[i].desc);
    }

}
void ShowPlayers()
{
    int i,j;
    if(players == NULL)
        return;
    printf("���\t���\t����\n");
    for(i=0; i<playerCount; i++)
    {
        printf("%-5d%-7.2lf\t%s\n",players[i].id,players[i].gold, players[i].name);
        for(j=0; j<players[i].bag.count; j++)
        {
            if(players[i].bag.props[j].stock > 0)
            {
                printf("\t%s\t%d\t\n",players[i].bag.props[j].name,players[i].bag.props[j].stock);
            }
        }

    }
}

void Trade(Player *player,int propId, int propNum)
{
    int i;
    //��Ҫ�ж�: 1 ��Ʒ�Ŀ�� 2 ��ҵĽ�� 3 �����Ŀռ�
    Prop *tradeProp = NULL; //��Ҫ�������Ʒָ��
    for(i=0; i<propCount; i++)
    {
        if(propId == props[i].id)
        {
            tradeProp = &props[i];  //tradeProp = props + i
            break;
        }
    }
    if(tradeProp->stock < propNum)
    {
        printf("<<%s>>��治��!!!\n",tradeProp->name);
        return;
    }
    if(player->gold < tradeProp->price * propNum)
    {
        printf("<<%s>>�û�����!!!\n",player->name);
        return;
    }
    if(player->bag.count + propNum > player->bag.max)
    {
        printf("<<%s>>�û������ռ䲻��!!!\n",player->name);
        return;
    }

    //�������� ִ�н������ݴ���
    //�߼�: �ж���ұ������Ƿ����и���Ʒ

    tradeProp->stock -= propNum;
    player->gold -= tradeProp->price * propNum;
    for(i=0; i<player->bag.count; i++)
    {
        //����и���Ʒ,������ĳ����Ʒ����+1
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock += propNum;
            player->bag.count += propNum;
            break;
        }
    }
//���û�и���Ʒ,����һ��Ҫ���׵���Ʒ��Ϣ��������
    if(i == player->bag.count)
    {
        int newIdex = player->bag.count;
        player->bag.props[newIdex].id = tradeProp->id;
        player->bag.props[newIdex].price = tradeProp->price;
        player->bag.props[newIdex].stock = propNum;
        strcpy(player->bag.props[newIdex].name,tradeProp->name);
        strcpy(player->bag.props[newIdex].desc,tradeProp->desc);
        player->bag.count+=propNum;
    }
}
