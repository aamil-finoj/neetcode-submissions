/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        if (r1 > r2 || c1 > c2) return nullptr;

        if (r1 == r2) {
            return new Node(grid[r1][c1], true);
        }

        int rowMid = r1 + (r2 - r1) / 2;
        int colMid = c1 + (c2 - c1) / 2;

        bool check_1 = true;
        int temp_1 = grid[r1][c1];
        for (int i = r1; i <= rowMid; i++) {
            for (int j = c1; j <= colMid; j++) {
                if (grid[i][j] != temp_1) {
                    check_1 = false;
                    break;
                }
            }
            if (!check_1) break;
        }

        bool check_2 = true;
        int temp_2 = grid[r1][colMid + 1];
        for (int i = r1; i <= rowMid; i++) {
            for (int j = colMid + 1; j <= c2; j++) {
                if (grid[i][j] != temp_2) {
                    check_2 = false;
                    break;
                }
            }
            if (!check_2) break;
        }

        bool check_3 = true;
        int temp_3 = grid[rowMid + 1][c1];
        for (int i = rowMid + 1; i <= r2; i++) {
            for (int j = c1; j <= colMid; j++) {
                if (grid[i][j] != temp_3) {
                    check_3 = false;
                    break;
                }
            }
            if (!check_3) break;
        }

        bool check_4 = true;
        int temp_4 = grid[rowMid + 1][colMid + 1];
        for (int i = rowMid + 1; i <= r2; i++) {
            for (int j = colMid + 1; j <= c2; j++) {
                if (grid[i][j] != temp_4) {
                    check_4 = false;
                    break;
                }
            }
            if (!check_4) break;
        }

        Node* root = new Node();

        if ((check_1 && check_2 && check_3 && check_4) && (temp_1 == temp_2 && temp_2 == temp_3 && temp_3 == temp_4)) {
            root->val = temp_1;
            root->isLeaf = true;
            return root;
        } else {
            root->isLeaf = false;
            root->val = temp_1;

            if (check_1) root->topLeft = new Node(temp_1, true);
            else root->topLeft = solve(grid, r1, rowMid, c1, colMid);

            if (check_2) root->topRight = new Node(temp_2, true);
            else root->topRight = solve(grid, r1, rowMid, colMid + 1, c2);

            if (check_3) root->bottomLeft = new Node(temp_3, true);
            else root->bottomLeft = solve(grid, rowMid + 1, r2, c1, colMid);

            if (check_4) root->bottomRight = new Node(temp_4, true);
            else root->bottomRight = solve(grid, rowMid + 1, r2, colMid + 1, c2);
        }

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return nullptr;
        return solve(grid, 0, n - 1, 0, n - 1);
    }
};