#include <stdio.h>
#include <stdlib.h>
#define  N 5
int main()
{
    int array[N] = {11,22,33,44,55};
    //ʵ����������� - ԭ������������βԪ�ؽ��н���
    int temp;  //��ʱ����
    int i;
    int * ptr_array = array;      //ָ��������Ԫ�ص�ָ��
    int * ptr_array_start = array;      //ָ��������Ԫ�ص�ָ��
    int * ptr_array_end = array + N -1;      //ָ������ĩԪ�ص�ָ��
    while(ptr_array_start != ptr_array_end)  //֧��ż����Ԫ�ص�����
    {
        //��β������ָ��ֱ���н���
        temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        //��Ԫ��ָ��Ҫ����ƶ�
        ptr_array_start++;
        //ĩԪ��ָ��Ҫ��ǰ�ƶ�
        ptr_array_end--;
    }

    for(i=0; i<N; i++)
    {
        printf("��ֵ��%d����ַ��%p\n",*ptr_array,ptr_array);
        ptr_array++;
    }



    return 0;
}
