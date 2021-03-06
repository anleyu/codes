#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
模拟实现道具店购物功能(商店暂时只支持一种的商品)
商品具备名称 价格 库存等属性
模拟玩家购买游戏道具
1 玩家选择要购买的道具
2 玩家同意交易后扣除相应的游戏币
3 对应商品库存-1
5 玩家背包中增加商品或商品数量+1
*/

//定义商品(道具)结构
typedef struct _prop
{
    int id; //道具唯一的编号
    char name[50];
    double price;
    int stock;  //库存量:如果在背包中表示叠加数量
    char desc[200]; //道具的功能描述
} Prop;

//背包结构
typedef struct _bag
{
    int payerId;     //所属玩家的编号
    int count;       //当前背包中道具的数量
    int max;         //当前背包中的插槽总数
    Prop props[8];   //当前背包中的道具数量
} Bag;

//玩家结构
typedef struct _player
{
    int id;           //玩家编号
    char name[50];    //用户名/昵称
    char pass[50];    //密码
    Bag bag;          //玩家的背包
    double gold;      //玩家金币-人性显示:可以是不同单位
    double sysee;     //元宝数量 - 货币单位
} Player;

Prop *props;
Player *players;
int propCount = 0;
int playerCount = 0;


//数据初始化
void Init();
//显示道具数据
void ShowProps();
//显示玩家数据
void ShowPlayers();
/**
*交易函数
*参数1 参与交易的玩家指针 - 为了方便交易过程操作玩家数据
*参数2 玩家所购买的商品id
*/
void Trade(Player *player,int propId,int propNum);


int main()
{
//初始化数据
    printf("**************数据初始化**************\n");
    Init();
    printf("**************商品列表**************\n");
    ShowProps();
    printf("**************玩家列表**************\n");
    ShowPlayers();

//执行交易处理

//输入交易参数
    int playId;  //玩家编号
    int propId;   //商品编号
    int propNum;  //购买数量
    char retrade[3];  //是否继续交易

    do
    {
        printf("\n玩家编号:");
        scanf("%d",&playId);
        printf("\n商品编号:");
        scanf("%d",&propId);
        printf("\n购买数量:");
        scanf("%d",&propNum);

        Trade(&players[playId-1],propId,propNum);
        printf("\n**************消费后**************\n");
        ShowPlayers();
        printf("\n是否继续购买y/n:");
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
        {1,"双倍经验卡",3000,100,"双击666"},
        {2,"腐烂的道袍",5000,8,"只可远观不可把玩!"},
        {3,"生锈的铁剑",8000,100,"水火不侵,伤害爆表"},
        {4,"直升1级丹",83000,100,"吃了之后摇头晃脑"}
    };

    props = propArray;  //设定指针的秩序
    propCount = sizeof(propArray)/sizeof(Prop);
    static Player playerArry[]=
    {
        {1,"超级毛毛虫","13456",.gold=5000,.bag.max=8},
        {2,"不安分的婊子","13456",.gold=15000,.bag.max=8},
        {3,"玉皇大帝","13456",.gold=50000,.bag.max=8},
        {4,"星河","13456",.gold=115000,.bag.max=8}
    };
    players = playerArry;
    playerCount = sizeof(playerArry)/sizeof(Player);

}
void ShowProps()
{
    int i;
    if(props == NULL)
        return;
    printf("%-5s%-14s%-8s库存\t商品介绍\n","编号","名称","单价");
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
    printf("编号\t金币\t名称\n");
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
    //需要判断: 1 商品的库存 2 玩家的金额 3 背包的空间
    Prop *tradeProp = NULL; //需要购买的商品指针
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
        printf("<<%s>>库存不足!!!\n",tradeProp->name);
        return;
    }
    if(player->gold < tradeProp->price * propNum)
    {
        printf("<<%s>>用户余额不足!!!\n",player->name);
        return;
    }
    if(player->bag.count + propNum > player->bag.max)
    {
        printf("<<%s>>用户背包空间不足!!!\n",player->name);
        return;
    }

    //满足条件 执行交易数据处理
    //逻辑: 判断玩家背包中是否已有该商品

    tradeProp->stock -= propNum;
    player->gold -= tradeProp->price * propNum;
    for(i=0; i<player->bag.count; i++)
    {
        //如果有该商品,背包中某个商品总数+1
        if(propId == player->bag.props[i].id)
        {
            player->bag.props[i].stock += propNum;
            player->bag.count += propNum;
            break;
        }
    }
//如果没有该商品,复制一份要交易的商品信息到背包中
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
