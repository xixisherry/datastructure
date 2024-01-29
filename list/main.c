# include "list_operations.h"
# include "list_operations.c" // 不建议这么做

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