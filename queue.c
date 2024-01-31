#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int elemtype;
typedef struct {
    int *nums;       // 用于存储队列元素的数组
    int front;       // 队首指针，指向队首元素
    int queSize;     // 尾指针，指向队尾 + 1
} ArrayQueue;

void initQueue(ArrayQueue *queue){
    queue->nums = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    queue->queSize = 0;
    queue->front = 0;
}

