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

    void inorder(TreeNode* root, int& ans, int k, int& count){

        if (root==nullptr) return;

        inorder(root->left, ans, k, count);
        
        count++;
        if (count==k){
            ans = root->val;
            return;
        }

        inorder(root->right, ans, k, count);
 
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        inorder(root, ans, k, count);

        return ans;
    }
};
