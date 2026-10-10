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



    bool solve(TreeNode* root, int lb, int ub){

        if (root==nullptr) return true;

        if (root->val <= lb || root->val >= ub) return false;

        return solve(root->left, lb, root->val) && solve(root->right, root->val, ub);

    }

    bool isValidBST(TreeNode* root) {
        
        if (root == nullptr) return true;

        int lb = INT_MIN, ub = INT_MAX;

        return solve(root, lb, ub);

    }
};
