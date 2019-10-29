 /**
 * 2019:10:29
 * leetcode-cn-235
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
 * 递归方法
 * 利用二叉搜索树的特定
 * 对于p和q如果他们都小于root，则他们都在左子树，如果都大于root，则在右子树
 * 反之 root就是他们的公共祖先
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else return root;
    }
};
 /*
 * 迭代方法
 * 由于不需要回溯，所以可以不利用栈和递归。
 * 使用迭代的主要地方是找到需要分割的点，然后根据点进行分割，最终找到结果
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val, qv = q->val;
        while(root) {
            if(pv < root->val && qv < root->val) root = root->left;
            else if(pv > root->val && qv > root->val) root = root->right;
            else return root;
        }
    }
};
