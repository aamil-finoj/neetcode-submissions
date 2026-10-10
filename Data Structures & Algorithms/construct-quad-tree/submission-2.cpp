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

        int temp = grid[r1][c1];
        bool isLeaf = true;

        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] != temp) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }

        if (isLeaf) {
            return new Node(temp, true);
        }

        int rowMid = r1 + (r2 - r1) / 2;
        int colMid = c1 + (c2 - c1) / 2;

        Node* root = new Node(temp, false);
        
        root->topLeft     = solve(grid, r1, rowMid, c1, colMid);
        root->topRight    = solve(grid, r1, rowMid, colMid + 1, c2);
        root->bottomLeft  = solve(grid, rowMid + 1, r2, c1, colMid);
        root->bottomRight = solve(grid, rowMid + 1, r2, colMid + 1, c2);

        return root;


    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return nullptr;
        return solve(grid, 0, n - 1, 0, n - 1);
    }
};