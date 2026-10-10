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

    int solve(TreeNode* root, unordered_map<TreeNode*, int>& m){

        if (root == nullptr) return 0;

        if (m.count(root)) return m[root];

        int ans = root->val;

        if (root->left)
            ans+= solve(root->left->left, m) + solve(root->left->right, m);

        if (root->right)
            ans+= solve(root->right->left, m) + solve(root->right->right, m);

        ans = max(ans, solve(root->left, m) + solve(root->right, m));

        m[root] = ans;

        return ans;

    }

    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*, int> m;

        return solve(root, m);

    }
};