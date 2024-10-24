#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

int init(FILE *fp,Node* tail)
{
    //读取换行符
    fgetc(fp);

    //创建链表
        Node * p=(Node*)malloc(sizeof(Node));
        p->next=NULL;
        tail->next=p;
        tail=p;

    //初始化
        for(int i=0;i<=32;i++)
        {
            p->decimal[i]=0;
            p->integer[i]=0;
        }

    //检测符号位，没有则结束
        if((p->signal=fgetc(fp))==EOF)
        return 0;
        
    //输入
        fscanf(fp,"%s",p->str);
        deal_putin(p);
        

    //自调用，继续读入
        init (fp,tail);

        return 1;
}