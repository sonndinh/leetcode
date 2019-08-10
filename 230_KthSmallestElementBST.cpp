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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        int count = 0;
        
        TreeNode *curr = root;
        while (true) {
            while (curr) {
                if (curr->left) {
                    s.push(curr->left);
                    curr = curr->left;
                } else {
                    break;
                }
            }
            
            while (!curr->right) {
                ++count;
                if (count == k) return curr->val;
                s.pop();
                curr = s.top();
            }
            ++count;
            s.pop();
            if (count == k) return curr->val;
            s.push(curr->right);
            curr = curr->right;
        }
        
        return curr->val;
    }
    
    // Return pointer to the k-th smallest node and the number of nodes 
    // smaller or equal to the current node in the subtree rooted at this node.
    pair<TreeNode*, int> inorder_traversal(TreeNode *node, int k) {
        if (!node) 
            return {nullptr, 0};
        
        // Search on the left side.
        auto left_ret = inorder_traversal(node->left, k);
        if (left_ret.first) 
            return left_ret;
        
        // Return if the current node is the k-th smallest.
        if (left_ret.second + 1 == k)
            return {node, k};

        // Search on the right side.
        int updated_k = k - left_ret.second - 1;
        auto right_ret = inorder_traversal(node->right, updated_k);
        if (right_ret.first)
            return right_ret;
        return {nullptr, left_ret.second + 1 + right_ret.second};
    }
    
    // Use inorder traversal. Time O(n). Space O(h) (call stack).
    int kthSmallest1(TreeNode* root, int k) {
        auto ret = inorder_traversal(root, k);
        if (ret.first)
            return ret.first->val;
        return 0;
    }
};
