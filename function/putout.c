#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
//打印链表
void putout_all(Node *p)
{
     if(p->next!=NULL)
     {
      printf("%c ",p->signal);
      for(int i=0;i<=strlen(p->integer);i++)
      {
        if(p->integer[i]!='+')
        printf("%c",p->integer[i]);
      }
        
        printf(".");
      for(int i=1;i<=strlen(p->decimal);i++)
        printf("%c",p->decimal[i]);
        printf("%c\n",p->form);
        putout_all(p->next);
     }
}
//打印结果
void putout_result(char *result)
{
  if(result[0]=='-')
  printf("-");
  int n=strlen(result)-1;
  
  for(int i=1;i<=n-length_decimal;i++)
     printf("%c",result[i]);

  printf(".");

  for(int i=n-length_decimal+1;i<=n;i++)
    printf("%c",result[i]);  

  printf("\n");  
}