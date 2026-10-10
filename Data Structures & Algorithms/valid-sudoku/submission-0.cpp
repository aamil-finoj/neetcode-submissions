class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++) {
            vector<bool> checker(9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                if (checker[idx]) return false;
                else checker[idx] = true;
            }
        }

        for (int j = 0; j < 9; j++) {
            vector<bool> checker(9, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '1';
                if (checker[idx]) return false;
                else checker[idx] = true;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> checker(9, false);

                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+1][j] != '.') {
                    int idx = board[i+1][j] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+2][j] != '.') {
                    int idx = board[i+2][j] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i][j+1] != '.') {
                    int idx = board[i][j+1] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i][j+2] != '.') {
                    int idx = board[i][j+2] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+1][j+1] != '.') {
                    int idx = board[i+1][j+1] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+1][j+2] != '.') {
                    int idx = board[i+1][j+2] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+2][j+1] != '.') {
                    int idx = board[i+2][j+1] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
                if (board[i+2][j+2] != '.') {
                    int idx = board[i+2][j+2] - '1';
                    if (checker[idx]) return false;
                    else checker[idx] = true;
                }
            }
        }

        return true;
    }
};