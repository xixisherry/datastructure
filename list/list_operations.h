// list_operations.h
#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxsize 100
#define initsize 10
typedef int elemtype;

typedef struct {
    int length;
    elemtype *data;
} sqList;


void InitList(sqList *L);

int leng(sqList L);

bool insert(sqList *L,int i,elemtype e);

bool delete1(sqList *L, int i, elemtype *e);

int Locate(sqList L,elemtype e);

elemtype getElem(sqList L, int i);

#endif //LIST_OPERATIONS