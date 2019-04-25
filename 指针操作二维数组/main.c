#include <stdio.h>
#include <stdlib.h>

int main()
{

    //数组名就是数组的首地址（数组首元素地址）
    //二维数组的理解：1-是由n个1维数组所组成
    int i,j;
    double score[5][3] =
    {
        {23,55,66},
        {45,67,12},
        {27,89,75},
        {56,66,88},
        {11,22,43},
        {13,52,49},
    };
    //遍历数组
    for(i=0; i<5; i++)
    {

        for(j=0; j<3; j++)
        {
            //数组写法
            //printf("%.2lf\t",score[i][j]);
            //指针写法
             printf("%.2lf\t",*(*(score+i)+j));
        }

        printf("\n");
    }


    return 0;
}
