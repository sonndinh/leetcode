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
    // Use BFS to traverse.
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            result.push_back(vector<int>());
            
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                result[level].push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ++level;
        }
        
        return result;
    }
    
    // Visit level k.
    void visit(TreeNode *node, int k, vector<vector<int>>& result) {
        if (node->left)
            visit(node->left, k+1, result);
        
        if (result.size() <= k)
            result.resize(k+1);
        result[k].push_back(node->val);
        
        if (node->right)
            visit(node->right, k+1, result);
    }
    
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) 
            return result;
        
        visit(root, 0, result);
        return result;
    }
};
