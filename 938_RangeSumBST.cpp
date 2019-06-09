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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        
        int sum = 0;
        if (root->val >= L && root->val <= R) {
            sum += root->val;
            sum += rangeSumBST(root->left, L, root->val);
            sum += rangeSumBST(root->right, root->val, R);
        } else if (root->val < L) {
            sum += rangeSumBST(root->right, L, R);
        } else if (root->val > R) {
            sum += rangeSumBST(root->left, L, R);
        }
        
        return sum;
    }
};
