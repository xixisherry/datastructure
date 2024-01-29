/**
 * 从顺序表中删除具有最小值的元素（假设唯一），并返回被删元素的值，空出的位置，最后一个元素填补
 * 
 * 1. 顺序表为空返回错误信息
 * 2. 找到最小值
 * 3. length-- 来消除最后一个元素
*/

# include <stdio.h>
typedef struct 
{
    /* data */
    int length;
    int *data;

}sqList;

int retMin(sqList *L){
    if (L->length == 0){
        printf("error\n");
        return -1;
    }
    int b = L->data[L->length -1];
    int c = L->data[0]; // 存放最小元素
    int pos = 0;
    for(int i = 0; i< L->length; i++){
        if(c > L->data[i]){
            c = L->data[i];
            pos = i; //切换到最小值的索引
        }

    }

    L->data[pos] = b;
    L->length--;
    printf("%d\n", c);
    return c;
}

