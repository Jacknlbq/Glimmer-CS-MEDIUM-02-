//用于存储每个数的各项信息
 typedef struct Node{
    int l;//小数位数
    int inte;
    struct Node* next;
    char integer[33],decimal[33],str[66];
    char signal,form;
}Node;
#include <stdio.h>


//结果的小数位数
#ifndef  GLOBALS_H
#define GLOBAL_H
extern int length_decimal;

#endif

void putout_all(Node *p);
void delete(Node *p);
int init(FILE *fp,Node* tail);
int turn(Node *p);
void multiply(char *A,char *B,char *C);
void  plus(char *A,char *B,char *C);
void minus(char *A,char *B,char *C);
void int_char(int a,char *A);
void   compare(char *a,char *b);
void addsign(char *a);
void  addzero(Node* p);
void splice(Node* p,char *A);
void deal_putin(Node* p);
void calculate(char *result,Node* A);
void alignment(char *A,int n);
void putout_result(char *result);
void discard(char *result);