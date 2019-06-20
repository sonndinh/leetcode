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
    // Return 2 values: maximum sum of this subtree from path that may or may not
    // go through this node AND maximum sum of path ending at this node.
    pair<int, int> visit(TreeNode* node) {
        if (!node)
            return {numeric_limits<int>::min(), numeric_limits<int>::min()};
        
        auto left = visit(node->left);
        auto right = visit(node->right);
        
        // Path with maximum sum from the two subtrees.
        int max_children = max(left.first, right.first);
        
        // Maximum sum of path going through this node.
        int max_through_node = node->val + max(left.second, 0) + max(right.second, 0);
        int max_end_at_node = node->val + max(max(left.second, 0), max(right.second, 0));
        
        return {max(max_children, max_through_node), max_end_at_node};
    }
    
    int maxPathSum(TreeNode* root) {
        pair<int, int> ret = visit(root);
        return ret.first;
    }
};
