#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> nums = {1,2,3,5};

    for(auto it = nums.begin(); it != nums.end(); it++){     
        cout << *it<<" ";
    }
    for(auto it = nums.begin(); it != nums.end(); it++){
        cout<<*it<< " ";
    }
    return 0;
}

