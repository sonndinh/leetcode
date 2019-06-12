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
    void visit(TreeNode *node, int& max_depth, int curr_depth, vector<int>& ret) {
        if (!node) return;
        
        if (curr_depth > max_depth) {
            // Get this node.
            ret.push_back(node->val);
            max_depth = curr_depth;
        }
        
        visit(node->right, max_depth, curr_depth+1, ret);
        visit(node->left, max_depth, curr_depth+1, ret);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        int max_depth = -1;
        visit(root, max_depth, 0, ret);
        return ret;
    }
};
