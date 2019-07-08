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
    bool dfs(TreeNode *node, TreeNode *target, vector<TreeNode*>& path) {
        if (node == target) {
            path.push_back(node);
            return true;
        }
            
        path.push_back(node);
        if (node->left) {
            if (dfs(node->left, target, path))
                return true;
        }
        if (node->right) {
            if (dfs(node->right, target, path))
                return true;
        }
        path.pop_back();
        return false;
    }
    
    // Find all nodes with distance k to @node from its subtrees.
    // Assumming @k >= 0.
    void get_nodes(TreeNode *node, vector<int>& ret, int k) {
        if (!node) return;
        
        if (k == 0) {
            ret.push_back(node->val);
            return;
        }
		get_nodes(node->left, ret, k - 1);
		get_nodes(node->right, ret, k - 1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path; // Path from root to target.
        dfs(root, target, path);
        
        vector<int> ret;
        for (int i = path.size() - 1; i >= 0; --i) {
            int dist = path.size() - 1 - i; // Distance from target to the current node.
            if (K - dist == 0) {
                ret.push_back(path[i]->val);
            } else if (K - dist > 0) {
                if (i == path.size() - 1) {
                    get_nodes(target->left, ret, K-1);
                    get_nodes(target->right, ret, K-1);
                } else {
                    if (path[i+1] == path[i]->left) {
                        get_nodes(path[i]->right, ret, K - dist - 1);
                    } else {
                        get_nodes(path[i]->left, ret, K - dist - 1);
                    }
                }
            }
        }
        
        return ret;
    }
};
