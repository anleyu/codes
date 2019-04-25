#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cJSON.h"

int main()
{
        cJSON * usr;
        cJSON *arry;

        usr=cJSON_CreateObject();   //创建根数据对象
        cJSON_AddStringToObject(usr,"name","fengxin");  //加入键值，加字符串
        cJSON_AddStringToObject(usr,"passwd","123");
        cJSON_AddNumberToObject(usr,"num",1);  //加整数

        char *out = cJSON_Print(usr);   //将json形式打印成正常字符串形式
        printf("%s\n",out);

        // 释放内存
        cJSON_Delete(usr);
        free(out);

}
