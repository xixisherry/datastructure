#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void FloorPrint_QUEUE(TreeNode* Tree) //层序遍历_队列实现
{
    queue<TreeNode *> q;
    if(Tree){ // 注意此处更改
        q.push(Tree);
    }
    while(!q.empty()){
        cout << q.front()->val << " ";
        if(q.front()->left != nullptr){
            q.push(q.front()->left);
        }
        if(q.front()->right != nullptr){
            q.push(q.front()->right);
        }
        q.pop();
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "层序遍历结果为：";
    FloorPrint_QUEUE(root);
    cout << endl;

    return 0;
}



#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        
        // 检查 nums1 和 nums2 是否为空
        if (!nums1.empty())
            merged.insert(merged.end(), nums1.begin(), nums1.end());  // insert
        if (!nums2.empty())
            merged.insert(merged.end(), nums2.begin(), nums2.end());
        
        sort(merged.begin(), merged.end());   // sort

        int n = merged.size();
        if (n % 2 == 0) {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        } else {
            return merged[n / 2];
        }
    }
};
