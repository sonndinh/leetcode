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
    void dfs(TreeNode *node, unordered_map<int, int>& depths, unordered_map<int, TreeNode*>& parents, int curr_depth) {
        depths[node->val] = curr_depth;
        
        if (node->left) {
            parents[node->left->val] = node;
            dfs(node->left, depths, parents, curr_depth+1);
        }
        if (node->right) {
            parents[node->right->val] = node;
            dfs(node->right, depths, parents, curr_depth+1);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == y) 
            return false;

        unordered_map<int, int> depths;
        unordered_map<int, TreeNode*> parents;
        dfs(root, depths, parents, 0);
        
        parents[root->val] = nullptr;
        if (depths[x] != depths[y] || parents[x] == parents[y])
            return false;
        return true;
    }
};
