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

    void solve(TreeNode* node, int val){


        if (val < node->val){
            if (node->left == nullptr){
                node->left = new TreeNode(val);
                return;
            }
            else solve(node->left, val);
        }

        if (val > node->val){
            if (node->right == nullptr){
                node->right = new TreeNode(val);
                return;
            }
            else solve(node->right, val);
        }

        return;

    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root==nullptr) return new TreeNode(val);
        
        TreeNode* node = root;

        solve(node, val);

        return root;


    }
};