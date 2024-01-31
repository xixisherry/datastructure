//基于数组实现
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxsize 50
typedef int elemtype;
typedef struct
{
    /* data */
    elemtype data[maxsize];
    int top; // 栈顶指针
}sqStack;















//初始化
void initStack(sqStack *St){
    St->top = -1;
}

//判断空
bool isEmpty(sqStack St){
    if(St.top == -1)
        return true;
    else
        return false;
}

//进栈
void push(sqStack *St, elemtype e){
    if (St->top == maxsize-1)
    {
       printf("full");
       return;
    }
    St->data[++St->top] = e;
}

//出栈
elemtype pop(sqStack *St, elemtype e){
    if(St->top == -1){
        printf("Empty");
        return -1;
    }
    else{
        e = St->data[St->top];
        St->top--;
    }
    return e;
}

//查看栈内元素
void display(sqStack St){
    if(St.top == -1){
        printf("is empty");
    }
    for (int i = 0; i < St.top+1; i++)
    {
        printf("%d ", St.data[i]);
    }
    printf("\n");
}

int main(){
    sqStack stack;
    initStack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    display(stack);
    return 0;
}