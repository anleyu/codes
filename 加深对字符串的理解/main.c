#include <stdio.h>
#include <stdlib.h>

int main()
{
   //定义字符串的几种方式
   //字符串和字符数组的区别：最后一位是否是空字符\0
   //char names[] = {'a','b','c','d','e'};
   char names1[] = {'a','b','c','d','e','\0'};
   char names2[] = "abcde";


    printf("数组所占空间大小%d: ",sizeof(names1));
    printf("\n%s所占空间大小%d: ",names2,sizeof(names2));
    return 0;
}
