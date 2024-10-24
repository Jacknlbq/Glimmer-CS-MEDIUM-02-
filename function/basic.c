#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

//删除链表
void delete(Node *p)
{
    if(p->next!=NULL)
    delete(p->next);
    free(p);
}
//添符号‘+’
void addsign(char *a)
{
    int n=strlen(a);
    for(;n>0;n--)
    a[n]=a[n-1];
    a[0]='+';
}
//拼接整数与小数
void splice(Node* p,char *A)
{
    int n=strlen(p->integer)-1;
    strcpy(A,p->integer);

    for(int i=1;i<=p->l;i++)
    {
        A[i+n]=p->decimal[i];
    }
}

//给进制转换后小数位补零
void  addzero(Node* p)
{
    
    int n=strlen(p->decimal)-1,n1=p->l,n2=n;//转换后的小数位数
    for(int i=1;i<=n;i++)
    {
      p->decimal[n1]=p->decimal[n2];
      n1--;
      n2--;
    }
    for(int i=1;i<=p->l-n;i++)
    p->decimal[i]='0';
}
//给数补零，让两个数小数部分对齐。

void alignment(char *A,int n)
{
    int a=strlen(A)-1;
    for(int i=1;i<=n;i++)
       A[i+a]='0';
}


//去掉result整数部分中前面的0 以及小数部分的零

void discard(char *result)
{
    int l=strlen(result)-1,n=0;
    for(int i=1;i<=l-length_decimal;i++)
    {
         if(result[i]!='0')break;
         n++;
    }
    if(n!=0)
    for(int i=1;i<=l-n;i++)
    {
       result[i]=result[i+n];
       result[i+n]=0;
    }


    l=strlen(result)-1;
    int j=0;
    for(int i=l;i>l-length_decimal;i--)
    {
        if(result[i]!='0')
        break;
        j++;
        result[i]=0;
    }
    length_decimal-=j;

}
