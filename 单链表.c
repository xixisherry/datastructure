#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct Lnode
{
    Elemtype data;
    struct Lnode *next;
}Lnode, *linkList;

//初始化
bool InitList(linkList *L){
    *L = (Lnode*)malloc(sizeof(Lnode));
    (*L)->next = NULL;
    return true;
}

//不带头结点的初始化
bool InitListNO(linkList *L){
    *L = NULL;
    return true;
}

//求表长
int Length(linkList L){
    int len = 0;
    while(L->next != NULL){
        L = L->next;
        len++;
    }
    return len;
}

//按序号查找节点

int main(){
    linkList myList;
    InitList(&myList);
}
