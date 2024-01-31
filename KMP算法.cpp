#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(string pattern){
    int m = pattern.length(); //next数组长度
    vector<int> lps(m, 0); //存放next数组
    lps[1] = 0;
    int samelen = 0; // 表示公共前后缀长度
    int i = 1; //i是指从模式串第二个开始计算next值，因为第一个已经给出

    while(i < m){ //扫描模式串
        if(pattern[i] == pattern[samelen]){
            samelen++;
            lps[i] += samelen;
            i++;
        }else{
            if(samelen != 0){
                samelen = lps[samelen - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> matches;
    int n = text.length();
    int m = pattern.length();
    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return matches;
}



int main() {
    string text = "ABABDAABAC";
    string pattern = "AABAC";
    
    vector<int> matches = KMP(text, pattern);
    
    if (matches.size() > 0) {
        cout << "Pattern found at positions: ";
        for (int i = 0; i < matches.size(); i++) {
            cout << matches[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }
    
    // 输出next数组
    cout << "Next array: ";
    vector<int> next = computeLPS(pattern);
    for (int i = 0; i < next.size(); ++i) {
        cout << next[i] << " ";
    }
    cout << endl;

    return 0;
}

