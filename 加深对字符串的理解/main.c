#include <stdio.h>
#include <stdlib.h>

int main()
{
   //�����ַ����ļ��ַ�ʽ
   //�ַ������ַ�������������һλ�Ƿ��ǿ��ַ�\0
   //char names[] = {'a','b','c','d','e'};
   char names1[] = {'a','b','c','d','e','\0'};
   char names2[] = "abcde";


    printf("������ռ�ռ��С%d: ",sizeof(names1));
    printf("\n%s��ռ�ռ��С%d: ",names2,sizeof(names2));
    return 0;
}
