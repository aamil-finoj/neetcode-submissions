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
    int diameterOfBinaryTree(TreeNode* root) {
        
        unordered_map<TreeNode*, pair<int,int>> m;
        stack<TreeNode*> st;

        m[nullptr] = {0,0};
        st.push(root);

        while (!st.empty()){

            TreeNode* node = st.top();

            if (node->left && !m.count(node->left)){
                st.push(node->left);
            }
            else if (node->right && !m.count(node->right)){
                st.push(node->right);
            }
            else{

                st.pop();
                auto [leftHeight, leftDia] = m[node->left];
                auto [rightHeight, rightDia] = m[node->right];

                int height = 1 + max(leftHeight, rightHeight);
                int dia = max(max(leftDia, rightDia), leftHeight + rightHeight);

                m[node] = {height, dia};


            }



        }

        return m[root].second;


    }
};
