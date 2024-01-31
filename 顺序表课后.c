/**
 * 从顺序表中删除具有最小值的元素（假设唯一），并返回被删元素的值，空出的位置，最后一个元素填补
 * 
 * 1. 顺序表为空返回错误信息
 * 2. 找到最小值
 * 3. length-- 来消除最后一个元素
*/

# include <stdio.h>
# include <stdbool.h>
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



/**
 * 将顺序表L的所有元素逆置，要求空间复杂度为o(1)
 * 
 * 先思考有哪些方法
方法一：使用额外的数组
创建一个额外的数组，将原始数组的元素逆序复制到额外数组中。
将额外数组的元素复制回原始数组。
空间复杂度：O(n)，需要额外的数组空间来存储逆序后的元素。

方法二：使用两个指针
使用两个指针，一个从数组的起始位置开始，另一个从数组的末尾开始。
交换两个指针所指向的元素，然后分别将两个指针向中间移动，直到它们相遇。
空间复杂度：O(1)，只需要常量级的额外空间来存储临时变量。

方法三：就地逆置
从数组的两端开始，依次交换元素直到数组中间。
空间复杂度：O(1)，只需要常量级的额外空间来存储临时变量。

方法四：使用递归
使用递归的方式，从数组的两端开始交换元素。
空间复杂度：O(log n)，递归调用的栈空间复杂度。
*/

//方法三：就地逆置
void reverse(sqList *L){
    int temp = 0;
    for(int i = 0; i< L->length / 2; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length-i-1];
        L->data[L->length-1-i] = temp;
    }
}




/*****
 * 3. 删除定值s到t之间的元素，要求s<t
*/

bool deleteSt(sqList *L, int s, int t){
    int k =0;
    if(s >= t){
        printf("ERROR");
        return false;
    }
    if(L->length == 0){
        printf("ERROR NO LENGTH");
        return false;
    }
    for(int i = 0; i<L->length; i++){
        if(s <= L->data[i] && L->data[i] <= t){
            k++;
        }
        else
        L->data[i - k] = L->data[i];
    }
    L->length -= k;
    return true;
}


/***
 * 4. 从有序顺序表中删除数值重复的元素，使表中元素均不相同
 * 
*/
int removeSame(sqList *L){
    if(L->length == 0){
        return 0;
    }
    for(int i = 0; i<L->length; i++){
        int j = 1;
        if(L->data[i]);
    }
}



