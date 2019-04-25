#include <stdio.h>
#include <stdlib.h> //标准库

int main()
{
    //演示动态分配内存
    int * nums;
    int i;
    nums = calloc(5,sizeof(int));
   // nums = (int *)malloc(sizeof(int) * 5);
    //等价nums = (int *)malloc(20);
    //也可以 nums = calloc(5,sizeof(int));

    //为前面的指针动态分配了20字节的空间
    //等价于 int nums[5];
    //为指针动态分配空间后，指针就变成了数组

    for(i=0;i<5;i++){
        printf("请输入第%d个元素",i+1);
        scanf("%d",nums+i);
    }
    printf("数组元素为：\n");
    for(i=0;i<5;i++){
        printf("%d\t",*(nums+i));
    }
    free(nums); //释放动态分配的内存
    nums = NULL; //良好的编程习惯
    return 0;
}
