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

    TreeNode* inorder(TreeNode* root){
        if (root==nullptr) return root;
        if (root->left == nullptr) return root;

        return inorder(root->left);
    }

    TreeNode* solve(TreeNode* root){

        if (root == nullptr) return root;

        if (root->left == nullptr) return root->right;
        
        else if (root->right == nullptr) return root->left;

        inorder(root->right)->left = root->left;

        return root->right;


    }


    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* original = root;
        
        if (root == nullptr) return root;
        if (root->val == key) return solve(root);

        while (root!=nullptr){

            if (root->val > key){
                if (root->left != nullptr && root->left->val == key){
                    root->left = solve(root->left);
                    break;
                }
                else root = root->left;
            }

            else{
                if (root->right != nullptr && root->right->val == key){
                    root->right = solve(root->right);
                    break;
                }
                else root = root->right;
            }

        }
        return original;

    }
};