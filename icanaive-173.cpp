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
 * 2019:10:23-173-icenaive
 * 使用栈模拟中序遍历，只是将过程分成三个函数
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;      // 首先入栈的是根个最左子树
        }
    }

    /** @return the next smallest number */
    int next() {
        auto temp = s.top()
        s.pop();
        root = temp->right;
        while(root) {
            s.push(root);
            root = root->left;          // 最左节点的右儿子的最左子树
        }
        return temp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();          // 判断栈是否为空就可以
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
