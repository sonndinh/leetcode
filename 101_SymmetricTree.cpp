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
    // Iterative version.
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({root->left, root->right});
        
        while (!que.empty()) {
            pair<TreeNode*, TreeNode*>& p = que.front();
            if ((p.first && !p.second) || (!p.first && p.second) || 
                (p.first && p.second && p.first->val != p.second->val))
                return false;
        
            if (p.first && p.second) {
                que.push({p.first->left, p.second->right});
                que.push({p.first->right, p.second->left});
            }
            que.pop();
        }
        return true;
    }
    
    bool verify(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if ((a && !b) || (!a && b) || (a && b && a->val != b->val))
            return false;
        return verify(a->left, b->right) && verify(a->right, b->left);
    }
    
    bool isSymmetric2(TreeNode* root) {
        if (!root)
            return true;
        return verify(root->left, root->right);
    }
};
