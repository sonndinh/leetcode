/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
    
public:
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top();
        s.pop();
        TreeNode *curr = t->right;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
