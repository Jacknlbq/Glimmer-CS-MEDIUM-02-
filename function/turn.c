#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int turn(Node *p)
{
    if(p->form!='B')
    {
        p->l=strlen(p->decimal);
        addsign(p->decimal);
        //所有整数部分在输入时就已经被添加了正号了，所以只给小数加符号
        return 0;
    }
    p->form='D';
    char integer[33]={0},decimal[33]={0};

    //转化为整数
    int sumi=0,sumd=0,index=1,vector=1;//计数器
    int n1=strlen(p->integer)-1,n2=strlen(p->decimal)-1;

    //小数位数
    p->l=n2+1;

    //在前面输入值时已经给整数部分添加了符号，所以i>0
    for(int i=n1;i>0;i--)
    {
        sumi+=(p->integer[i]-'0')*index;
        index*=2;
    }

    //小数处理 先全部进行移位操作
    index=1;
    for(int j=n2;j>=0;j--)
    {
        sumd+=(p->decimal[j]-'0')*index;
        index*=2;
        vector*=5;
    }
    //转化为字符并添加符号
    int_char(sumi,integer);
    int_char(sumd,decimal);
    
    //清空
    for(int q=0;q<=32;q++)
    {
        p->decimal[q]=0;
        p->integer[q]=0;
    }
   
    //移位
    char power[40]={0};
    int_char(vector,power);
    multiply(power,decimal,p->decimal);
    //给小数补零
    addzero(p);

    //复制
    strcpy(p->integer,integer);

}