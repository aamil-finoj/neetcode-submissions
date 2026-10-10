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

    void solve (TreeNode* root, int& ans, int maxSoFar){

        if (root == nullptr) return;

        if (root->val >= maxSoFar){
            ans++;
            maxSoFar = max(maxSoFar, root->val);
        }


        solve(root->left, ans, maxSoFar);
        solve(root->right, ans, maxSoFar);
        
        return;
    }

    int goodNodes(TreeNode* root) {

        if (root==nullptr) return 0;

        int ans = 0;
        int maxSoFar = root->val;
        solve(root, ans, maxSoFar);

        return ans;

    }
};
