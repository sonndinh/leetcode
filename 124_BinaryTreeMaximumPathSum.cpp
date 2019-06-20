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
    vector<int> visit(TreeNode* node) {
        if (!node)
            return {numeric_limits<int>::min(), numeric_limits<int>::min()};
        
        auto left = visit(node->left);
        auto right = visit(node->right);
        
        // Path with maximum sum from the two subtrees.
        int max_children = max(left[0], right[0]);
        
        // Maximum sum of path going through this node.
        int max_through_node = node->val;
        int max_end_at_node = node->val;
        if (left[1] > 0) {
            max_through_node += left[1];
            max_end_at_node += left[1];
        }
        if (right[1] > 0) {
            max_through_node += right[1];
            max_end_at_node = max(max_end_at_node, node->val + right[1]);
        }
        
        return {max(max_children, max_through_node), max_end_at_node};
    }
    
    int maxPathSum(TreeNode* root) {
        vector<int> ret = visit(root);
        return ret[0];
    }
};
