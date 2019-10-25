 /**
 * 2019:10:24
 * leetcode-cn-199
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

// 层次遍历， 每层的最后一个节点就是需要的结果
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> res;
        if(root) q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0;i < cnt;i++) {
                TreeNode *temp = q.front(); q.pop();
                if(cnt - 1 == i) res.push_back(temp->val);    // 最后一个节点
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};
