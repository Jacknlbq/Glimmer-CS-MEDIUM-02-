#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
//处理输入
void deal_putin(Node* p)
{
    int n=strlen (p->str);
    int i=0;

    //查找小数点
    for(;i<n;i++)
        if(p->str[i]=='.')break;

    if(p->str[0]=='-')
    for(int j=0;j<i;j++)
         p->integer[j]=p->str[j];
    else
    {
        for(int j=0;j<i;j++)
         p->integer[j+1]=p->str[j];
       p->integer[0]='+';
    }
    for(int j=i+1;j<n-1;j++)
       p->decimal[j-i-1]=p->str[j];

    p->form=p->str[n-1];
    turn(p);
}