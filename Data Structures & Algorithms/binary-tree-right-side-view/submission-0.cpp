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

    void levelOrder(TreeNode* root, vector<int>& ans){

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            
            int current_level = q.size();

            while (current_level > 0){

                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if (current_level == 1) ans.push_back(node->val);

                current_level--;

            }

        }

    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if (root == nullptr) return ans;

        //vector<vector<int>> levels;

        levelOrder(root, ans);

        return ans;

    }
};
