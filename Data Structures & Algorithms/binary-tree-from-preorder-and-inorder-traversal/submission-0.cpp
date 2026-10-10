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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& m, int& idx, int l, int r){

        if (l>r) return nullptr;

        int val = preorder[idx];
        TreeNode* node = new TreeNode(val);
        idx++;

        int temp = m[val];
        node->left = solve(preorder, inorder, m, idx, l, temp-1);
        node->right = solve(preorder, inorder, m, idx, temp+1, r);

        return node;

    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            
            int n = preorder.size();
            if (n==0) return nullptr;
            if (n==1) return new TreeNode(preorder[0]);

            unordered_map<int,int> m;
            for (int i=0; i<n; i++){
                m[inorder[i]] = i;
            }

            int idx=0;
            TreeNode* root = solve(preorder, inorder, m, idx, 0, n-1);

            return root;


    }
};
