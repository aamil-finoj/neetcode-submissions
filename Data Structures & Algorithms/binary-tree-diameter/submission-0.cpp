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

    int maxDepth(TreeNode* root){

        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int depth = 0;
        if (root->left != nullptr) depth+=(maxDepth(root->left));
        if (root->right != nullptr) depth+=(maxDepth(root->right));

        return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), depth);
    }
};
