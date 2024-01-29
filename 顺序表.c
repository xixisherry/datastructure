bool insert(sqList *L,int i,elemtype e){
    if(i < 1 || i > L->length+1)
        return False;
    if(L->length >= maxsize)
        return False;
    for(int j = L->length; j >= i; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;

}

bool delete1(sqList *L, int i, elemtype *e){ // 这里的e要用指针 *e
    if(i<1 || i>L->length + 1)
        return False;
    if(L->length <= 0){
        return False;
    }
    *e = L->data[i-1];  //这里的*不要忘记
    for (;i<L->length;i++){  //for (;i<length;i++)这是错误的，原因在于L->length
        L->data[i-1] = L->data[i];
    }
    // do not forget length--
    L->length--;
    return True;
}