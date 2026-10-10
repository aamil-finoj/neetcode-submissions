/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isLeaf(TreeNode* root){
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;

        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if (root == nullptr) return root;
        if (isLeaf(root)) return root;

        if (root->left && root->left->val == target && isLeaf(root->left)) root->left = nullptr;
        else root->left = removeLeafNodes(root->left, target);

        if (root->right && root->right->val == target && isLeaf(root->right)) root->right = nullptr;
        else root->right = removeLeafNodes(root->right, target);

        if (isLeaf (root) && root->val == target) return nullptr;
        
        return root;
    }
};