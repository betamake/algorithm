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
    vector<string> binaryTreePaths(TreeNode* root) {
         dfs(root, "", ans);
         return ans;
    }
private:
    vector<string> ans;
    void dfs(TreeNode *root,string path, vector<string> ans) {
        if(root) {
            path += to_string(root->val);
            if(nullptr == root->left && nullptr == root->right) {
                ans.push_back(path);
                path = "";
            }
        }
        else {
            path += "->";
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }
    }
};
