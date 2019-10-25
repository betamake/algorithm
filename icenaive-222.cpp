 /**
 * 2019:10:25
 * leetcode-cn-222
 * icenaive
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 遍历每一个点就可以
 // 递归算法 我的递归
class Solution {
private:
    int n = 0;
    void dfs(TreeNode *root) {
        //if(!root) return 0;
        n += 1;
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return n;
        dfs(root);
        return n;
    }

};
// 别人的递归 好像我的结果跑出来还更优
class Solution{
public:
    int countNodes(TreeNode *root) {
    if(!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
