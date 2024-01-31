#include <iostream>
#include <queue>
using namespace std;
#define maxsize 50

// //链式
// typedef int elemtype;

// typedef struct sqBitnode{
//     struct sqBitnode *lchild, *rchild;
//     int data;
// }sqBitnode,*sqBittree; //定义一个指向sqbitnode结构体的指针 sqbitreee

// typedef struct sqStack{
//     elemtype data[maxsize];
//     int top;
// }sqStack;



// void visit(sqBittree tree){ // 访问节点,具体操作可以自定义
//     cout<< tree->data <<endl;
// }
// //先序遍历
// void preorder(sqBittree tree){
//     if(tree != NULL){
//         visit(tree);
//         preorder(tree->lchild);
//         preorder(tree->rchild);
//     }
// }

// //中序遍历
// void midorder(sqBittree tree){
//     if(tree != NULL){
//         preorder(tree->lchild);
//         visit(tree);
//         preorder(tree->rchild);
//     }

// }

// //后序遍历
// void backorder(sqBittree tree){
//     if(tree != NULL){
//         preorder(tree->lchild);
//         preorder(tree->rchild);
//         visit(tree); 
//     }

// }

// //以下是非递归算法
// void Initstack(sqStack *S){
//     S->top = -1;
// }

// bool isempty(sqStack S){
//     if(S.top == -1)
//         return true;
//     else
//         return false;
// }

// void preorder1(sqBittree tree){
//     sqStack S;
//     Initstack(&S);
//     sqBittree p = tree;
//     while(p || !isempty(S)){

//     }
// }

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
    if(!Tree){
        q.push(Tree);
    }
    while(!q.empty()){
        cout<<q.front()->val;
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
    // 构建一个简单的二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 调用层序遍历方法
    cout << "result" << endl;
    FloorPrint_QUEUE(root);

    return 0;
}