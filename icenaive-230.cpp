 /**
 * 2019:10:28
 * leetcode-cn-230
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
 /*
 * 中序遍历为升序，所以中序遍历一次，存入数组，然后返回第k个就可以
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(1 == k) return root->val;
        dfs(root);
        return que[k - 1];
    }
private:
    vector<int> que;
    TreeNode *ans;
    void dfs(TreeNode* root) {
        if(root) {
            dfs(root->left);
            que.push_back(root->val);
            dfs(root->right);
        }
    }
};
