/***********
 *包含了线性表的一些基本操作，函数命名比较随意，可以参照注释进行阅读

************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define maxsize 100
#define initsize 10
typedef int elemtype;

//静态存储
/*
typedef struct{
    elemtype data[maxsize];
    int length;
}
*/

//动态存储
typedef struct {
    int length;
    elemtype *data;
} sqList;
/********************************
如果只谈论算法，只看下面的部分即可

*********************************/


// 初始化
void InitList(sqList *L){  //需要改变传入sqList的值，因此使用*L
    L->data = (elemtype*) malloc(sizeof(elemtype) * maxsize);
    L->length = 0;
}


//求表长
int leng(sqList L){  // 只是把L.length的值打印出，没有改变sqList本身，因此使用sqList L
    printf("the length of sqList is %d\n",L.length);
    return 0;
}

//在位置i插入一个元素e
bool insert(sqList *L,int i,elemtype e){
    if(i < 1 || i > L->length+1)  //注意这里的i，and思考为什么此处是length+1,而下面for循环中是length
        return false;
    if(L->length >= maxsize)
        return false;
    for(int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++; // do not foeget

    return true;
}

//在位置i删除一个e，并把值返回
bool delete1(sqList *L, int i, elemtype *e){ // 这里的e要用指针 *e
    if(i<1 || i>L->length + 1)
        return false;
    if(L->length <= 0){
        return false;
    }
    *e = L->data[i-1];  //这里的*不要忘记
    for (;i<L->length;i++){  //for (;i<length;i++)这是错误的，原因在于L->length
        L->data[i-1] = L->data[i];
    }
    // do not forget length--
    L->length--;

    return true;   
}

//顺序表L中查找第一个元素值为e的值，并返回位序(此处的位序不认为是索引，而是索引加一)
int Locate(sqList L,elemtype e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e){
            printf("find %d successful, located at position %d\n",e ,i);
            return i+1;
        }
    }
    return 0;
}
//顺序表按位置查找，获取表中位置i的元素的值
elemtype getElem(sqList L, int i){
    //判断i的位置是否合理
    if(i<1 || i > L.length){
        return -1;
    }
    else{
        printf("%d\n",L.data[i-1]);// 请一定注意这里，比如我们试图返回第一个元素,(即 i = 1)但是我们要写 L.data[i-1];因为数组是从0开始的。
        return L.data[i-1];
    }

}



/***************************
算法部分在已经结束
下面可忽视
***************************/
int main(){
    sqList my_list;
    InitList(&my_list);
    leng(my_list);
    insert(&my_list,1,10);
    insert(&my_list,2,11);
    Locate(my_list,11);
    getElem(my_list,2);
    leng(my_list);
    return 0;
}
