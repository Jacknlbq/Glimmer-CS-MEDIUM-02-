#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
void int_char(int a,char *A)
{
    int j=-1;
    int k=a;
    if(a==0)A[1]='0';

    while(k!=0)
    {
        j++;
        k/=10;
    }
    for(j+=1;j>0;j--)
    {
        A[j]=a%10+'0';
        a/=10;
    }
    A[0]='+';
 }   