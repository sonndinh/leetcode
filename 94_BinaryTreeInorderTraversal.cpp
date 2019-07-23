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
    vector<int> inorderTraversal(TreeNode *root) {
        // Iterative implementation.
        if (!root) return vector<int>();
        
        stack<TreeNode*> s;
        s.push(nullptr); // Store parents of the current nodes.
        vector<int> ret;
        
        TreeNode *node = root, *prev = nullptr;
        while (node) {
            if (prev == s.top()) {
                if (node->left) {
                    s.push(node);
                    prev = node;
                    node = node->left;
                } else {
                    ret.push_back(node->val);
                    if (node->right) {
                        s.push(node);
                        prev = node;
                        node = node->right;
                    } else {
                        prev = node;
                    }
                }
            } else if (prev == node->left) {
                ret.push_back(node->val);
                if (node->right) {
                    s.push(node);
                    prev = node;
                    node = node->right;
                } else {
                    prev = node;
                }
            } else {
                prev = node;
                node = s.top();
                s.pop();
            }
        }
        
        return ret;
    }
    
    void recursive_helper(TreeNode *node, vector<int>& ret) {
        if (!node) return;
        
        recursive_helper(node->left, ret);
        ret.push_back(node->val);
        recursive_helper(node->right, ret);
    }
    
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> ret;
        recursive_helper(root, ret);
        return ret;
    }
};
