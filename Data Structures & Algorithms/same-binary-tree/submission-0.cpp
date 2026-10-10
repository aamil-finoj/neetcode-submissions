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

    void preorder(TreeNode* root, vector<int>& arr){
        if (root==nullptr) {arr.push_back(-101); return;}
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> arr1, arr2;

        preorder(p, arr1);
        preorder(q, arr2);
        
        return (arr1 == arr2);

    }
};
