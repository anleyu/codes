#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    //����������������׵�ַ
    double score[] = {11,22,33,44,55,66,77,88};
    double * ptr_score = score;
    ptr_score = &score;
    printf("%p\n",ptr_score);
    for(i=0; i<8; i++)
    {
        //��һ�ַ��ʷ�ʽ
        // printf("%lf\n",ptr_score[i]);
        //�ڶ��ַ��ʷ�ʽ[ʵ�ʿ����Ƽ����ַ�ʽ]
         printf("%lf\n",*(ptr_score+i));
        //�����ַ�ɭ��ʽ ���Ƽ� ���׳������� ��Ҫ����ָ��
        //printf("%lf\n",*ptr_score++);
    }

    return 0;
}
