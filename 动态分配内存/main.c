#include <stdio.h>
#include <stdlib.h> //��׼��

int main()
{
    //��ʾ��̬�����ڴ�
    int * nums;
    int i;
    nums = calloc(5,sizeof(int));
   // nums = (int *)malloc(sizeof(int) * 5);
    //�ȼ�nums = (int *)malloc(20);
    //Ҳ���� nums = calloc(5,sizeof(int));

    //Ϊǰ���ָ�붯̬������20�ֽڵĿռ�
    //�ȼ��� int nums[5];
    //Ϊָ�붯̬����ռ��ָ��ͱ��������

    for(i=0;i<5;i++){
        printf("�������%d��Ԫ��",i+1);
        scanf("%d",nums+i);
    }
    printf("����Ԫ��Ϊ��\n");
    for(i=0;i<5;i++){
        printf("%d\t",*(nums+i));
    }
    free(nums); //�ͷŶ�̬������ڴ�
    nums = NULL; //���õı��ϰ��
    return 0;
}
