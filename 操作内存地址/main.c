#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num = 9;
   int * ptr_num = &num;
   int * ptr_num2 = &ptr_num;
   //%p指针占位符  %x 16进制占位符
    printf("num的变量地址:%p\t%x\n",ptr_num,ptr_num); //%p打印内存地址
    *ptr_num = 444;
    printf("num的变量的值:%d\n",*ptr_num);

    printf("ptr_num指针的地址:%p\n",ptr_num2);
    printf("ptr_num指针的地址:%p\n",ptr_num2);
    return 0;
}
