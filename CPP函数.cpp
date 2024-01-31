

//insert  insert(positon, insert object)
/**
 * insert(position, string name) 在指定位置插入指定名字的字符串
 * insert(position, times, char) 在指定位置position前，插入times个给定字符（char）
 * insert(position, string name, begin, size) 
*/
#include<iostream>
using namespace std;
int main()
{
    string str="hello"; 
    string s="Hahah";
    str.insert(1,s);//在原串下标为1的字符e前插入字符串s
    cout<<str<<endl;

    string str1="hello";
    char c='w';
    str1.insert(4,5,c);//在原串下标为4的字符o前插入5个字符c
    cout<<str1<<endl;

    string str2="hello";
    string s2="weakhaha";
    str2.insert(0,s2,1,3);//将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前
    cout<<str2<<endl;

    return 0;
}

