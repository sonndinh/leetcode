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
    void helper(TreeNode *node, int& count) {
        ++count;
        if (node->left)
            helper(node->left, count);
        if (node->right)
            helper(node->right, count);
    }
    
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        
        int count = 0;
        helper(root, count);
        return count;
    }
    
    /*
    int countNodes(TreeNode* root) {
        int height = -1;
        TreeNode *curr = root;
        while (curr) {
            ++height;
            curr = curr->left;
        }  
    }
    */
};
