#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

void   compare(char *a,char *b)
{
    int j=0;
    int n1,n2;
    n1=strlen(a);
    n2=strlen(b);
    if(n1==n2)
    {
        for(int i=1;i<=n1-1;i++)
        {
            if(a[i]<b[i])
        {
            j=1;
            break;
        }
        if(a[i]>b[i])
        break;
        }
    }
    if(n1<n2||j==1)
    {
        char d[50];
        strcpy(d,a);
        strcpy(a,b);
        strcpy(b,d);
    }
}