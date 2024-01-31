#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>

// using namespace std;
// int main(){
//     unordered_map<int, string> map;
//     map[12836] = "hello";
//     map[15937] = "yes我";
//     map[16750] = "我";
//     map[13276] = "这是";
//     map[10583] = "hello";

//     map.insert({15937,"ssss"});
//     string name = map[15937];
//     cout<< name<<endl;

//     map.erase(10583);
//     return 0;
// }

using namespace std;

int main(){
    unordered_map <int,string> hashmap;
    hashmap[1] = "hello";
    hashmap[2] = "111";

    hashmap.insert({12, "james"}); // insert({key,value})
    string name = hashmap[12];
    cout <<name<<endl;

    unordered_map <int,int> map{{1,2},{2,23},{3,22}};
    unordered_map <int,int> hmap(map); //复制构造
    
    unordered_map <int, int> ::iterator it = hmap.end();
    unordered_map <int, int>::iterator iter = hmap.begin();//和下一行等价
    auto iter1 = hmap.begin(); //和上一行等价

    hashmap.erase(1);//erase(key)
    return 0;
}

class Solution {
public:
        unordered_map<char, int> symbolvalue{   // unordered_map <key, value>;
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
    int romanToInt(string s) { //
        int ans = 0;
        int n = s.length();
        auto inter = s.begin();
        for(; inter != s.end(); inter++){
            int value = symbolvalue[*inter];
            if(inter<s.end()-1 && value< symbolvalue[*next(inter)]){
                ans -= value;
            }
            else ans += value;
        }
        return ans;
    }
};