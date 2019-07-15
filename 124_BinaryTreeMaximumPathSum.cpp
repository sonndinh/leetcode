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
    int max_sum = numeric_limits<int>::min();
    
public:
    // Return the maximum sum of a path from this node downwards to a leaf.
    int helper(TreeNode *node) {
        int max_left = 0, max_right = 0;
        if (node->left)
            max_left = max(0, helper(node->left));
        if (node->right)
            max_right = max(0, helper(node->right));
        
        if (node->val + max_left + max_right > max_sum)
            max_sum = node->val + max_left + max_right;
        
        return node->val + max(max_left, max_right);
    }
    
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int ret = helper(root);
        return max_sum;
    }
    
    
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
    
    int maxPathSum1(TreeNode* root) {
        pair<int, int> ret = visit(root);
        return ret.first;
    }
};
