#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>


void calculate(char *result,Node* p)
{ 
    char num1[66]={0},num2[66]={0};
    strcpy(num1,result);
    //拼接整数与小数
    splice(p,num2);
    //给数补零，让两个数小数部分对齐。
    if(length_decimal>p->l)
    {
        alignment(num2,length_decimal-p->l);
        p->l=length_decimal;
    }
    else{
        alignment(num1,p->l-length_decimal);
        length_decimal=p->l;
    }
   //清空result
   for(int i=0;i<=65;i++)
       result[i]=0;

    if(p->signal=='+')
    {
        plus(num1,num2,result);
        if(length_decimal<p->l)
         length_decimal=p->l;
    }
    if(p->signal=='-')
    {
        minus(num1,num2,result);
        if(length_decimal<p->l)
         length_decimal=p->l;
    }
    if(p->signal=='*')
    {
        multiply(num1,num2,result);
        length_decimal+=p->l;
    }
    //处理整数部分产生的零
    discard(result);

    //进行下一步计算
    if(p->next->next!=NULL)
    calculate(result,p->next);
}