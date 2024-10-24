#include "../head.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

int main()
{
    FILE* fp;
    fp = fopen("//home//zy//.vscode//test5//CS_M_02.txt","r");
    //输入第一个数
    Node * head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    for(int i=0;i<=32;i++)
        {
            head->decimal[i]=0;
            head->integer[i]=0;
        }
    fscanf(fp,"%s",&head->inte,head->decimal);
    head->form=head->decimal[strlen(head->decimal)-1];
    head->decimal[strlen(head->decimal)-1]=0;
    int_char(head->inte,head->integer);
    turn(head);
    Node *tail=head;
    //读入其他数以及它们的符号
    init (fp,tail);
    putout(head);
    delete(head);
    fclose(fp);
    return 0;
}