/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
//        if(root){
//            postorderTraversal(root->left);
//            postorderTraversal(root->right);
//            res.push_back(root->val);
//        }
//        return res;
        stack<TreeNode *> s;
        if(root) s.push(root);
        while(!s.empty()) {
            TreeNode *temp = s.top();
            res.insert(res.begin(), temp->val);
            s.pop();
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
        }
        return res;
    }
private:
    vector<int> res;
};
