class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j){

        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if (board[i][j] != 'O') return;
        
        if (board[i][j] == 'O') board[i][j] = 'S';

        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);

        return;

    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();
        
        for (int i : {0, n-1}){
            for (int j=0; j<m; j++){
                if (board[i][j] == 'X' || board[i][j] =='S') continue;
                dfs(board,i,j);
            }
        }

        for (int j : {0, m-1}){
            for (int i=0; i<n; i++){
                if (board[i][j] == 'X' || board[i][j] =='S') continue;
                dfs(board,i,j);
            }
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
        

        return;

    }
};
