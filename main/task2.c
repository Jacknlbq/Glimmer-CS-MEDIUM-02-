#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int length_decimal;
int main()
{

    FILE* fp;
    fp = fopen("//home//zy//.vscode//test5//CS_M_02.txt","r");
    //输入第一个数
    Node * head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->signal='+';
    for(int i=0;i<=32;i++)
        {
            head->decimal[i]=0;
            head->integer[i]=0;
        }
    fscanf(fp,"%s",head->str);
    deal_putin(head);
    Node *tail=head;


    //读入其他数以及它们的符号
    init (fp,tail); 


    //用于存储结果的result
    char result[66]={0};
    splice(head,result);
    
    //记录小数长度
    length_decimal=head->l;
    calculate(result,head->next);

    //输出结果
    putout_all(head);
    putout_result(result);
    //删除
    delete(head);
    fclose(fp);
    return 0;
}