#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

void multiply(char *A,char *B,char *C)
{
    int p=0,q=0;
    char e[100]={'+','0'};
    int n1=strlen(A),n2=strlen(B),n;
    for(int i=n2-1;i>0;i--)
    {
        n=n1;//初始化指向末尾
        char ch[100]={'+'},H[100]={0};
        for(int j=n1-1;j>0;j--)
        {
            q=(A[j]-'0')*(B[i]-'0')+p;
            ch[j]=q%10+'0';
            p=q/10;//进位数
        }
        if(p!=0)//后挪一位
        {
            for(int j=n1;j>1;j--)
            ch[j]=ch[j-1];
            ch[1]=p+'0';
            p=0;
            n+=1;//末尾进1
        }
        //补零
        for(int j=0;j<n2-1-i;j++)
        ch[n++]='0';

        plus(ch,e,H);
        strcpy(e,H);
    }
    strcpy(C,e);
    //符号
    if(A[0]!=B[0])C[0]='-';
    else C[0]='+';
}