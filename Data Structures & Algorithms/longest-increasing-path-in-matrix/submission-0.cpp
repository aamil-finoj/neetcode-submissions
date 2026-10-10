class Solution {

private:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n, m;
    int maxLength;

public:

    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){

        if (i>=m || j>=n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int res = 1;

        for (auto [dx,dy] : directions){
            int nx = i+dx;
            int ny = j+dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[i][j]) 
                res = max(res, 1+solve(nx, ny, dp, matrix));
        }

        return dp[i][j] = res;


    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();
        maxLength = INT_MIN;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int temp = solve(i,j,dp, matrix);
                maxLength = max(maxLength, temp);
            }
        }

        return maxLength;

    }
};
