// 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
// https://leetcode-cn.com/leetbook/read/top-interview-questions/xazo8d/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
     left(left), right(right) {}
};

int out = 0;
int count = 0;
void orderTravers(TreeNode* p) {
    if(p == nullptr) {
        return;
    }
    orderTravers(p->left);
    if(count != 0) {
        out = p->val;
        count--;
    }
    orderTravers(p->right);
}

int kthSmallest(TreeNode* root, int k) {
    count = k;
    orderTravers(root);
    return out;
}

int main()
{
    return 0;
}