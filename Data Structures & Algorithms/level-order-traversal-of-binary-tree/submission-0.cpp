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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root==nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int next_level_elems = 0;
        int curr_level = 1;

        while (!q.empty()){

            vector<int> temp;

            while (curr_level>0){

                TreeNode* node = q.front();
                q.pop();

                if (node->left){
                    next_level_elems++;
                    q.push(node->left);
                }
                if (node->right){
                    next_level_elems++;
                    q.push(node->right);
                }

                temp.push_back(node->val);
                curr_level--;

            }

            ans.push_back(temp);
            curr_level = next_level_elems;
            next_level_elems = 0;
            

        }

        return ans;

    }
};
