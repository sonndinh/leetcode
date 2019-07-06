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
    void add_leaves(TreeNode *node, vector<int>& boundary) {
        if (!node->left && !node->right) {
            boundary.push_back(node->val);
            return;
        }
        
        if (node->left)
            add_leaves(node->left, boundary);
        if (node->right)
            add_leaves(node->right, boundary);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return vector<int>();
        
        vector<int> boundary;
        TreeNode *curr = root;
        if (!root->left) {
            if (root->right)
                boundary.push_back(root->val);
        } else {
            while (curr) {
                if (curr->left || curr->right)
                    boundary.push_back(curr->val);
                if (curr->left)
                    curr = curr->left;
                else 
                    curr = curr->right;
            }
        }
            
        add_leaves(root, boundary);
        
        if (root->right) {
            curr = root->right;
            vector<int> temp;
            while (curr) {
                temp.push_back(curr->val);
                if (curr->right)
                    curr = curr->right;
                else 
                    curr = curr->left;
            }
            for (int i = temp.size()-2; i >= 0; --i) {
                boundary.push_back(temp[i]);
            }
        }
        
        return boundary;
    }
};
