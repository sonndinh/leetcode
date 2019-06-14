/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void visit(string& s, TreeNode *node) {
        if (!node) return;
        
        s += to_string(node->val) + " ";
        visit(s, node->left);
        visit(s, node->right);
    }
    
    // Rebuild a subtree with nodes from [left, right] of the array.
    TreeNode* rebuild(const vector<int>& arr, int left, int right) {
        if (left > right)
            return nullptr;
        
        int val = arr[left];
        TreeNode *node = new TreeNode(val);
        int i = left+1;
        while (i <= right && arr[i] <= val) {
            i++;
        }
        node->left = rebuild(arr, left+1, i-1);
        node->right = rebuild(arr, i, right);
        return node;
    }
    
public:    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Use preorder traversal data to encode.
        string s;
        visit(s, root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<int> arr;
        int a;
        while (ss >> a) {
            arr.push_back(a);
        }
        
        return rebuild(arr, 0, arr.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
