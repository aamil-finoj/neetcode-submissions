class Solution {

private: 
int n,m;

public:

    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){

        if (i == n) return m-j;
        if (j == m) return n-i;

        if (dp[i][j]!=-1) return dp[i][j];

        if (word1[i] == word2[j]) return dp[i][j] = solve(i+1, j+1, word1, word2, dp);
        
        int res = solve(i,j+1,word1,word2, dp); //inserting
        res = min(res, solve(i+1,j,word1,word2, dp)); //deleting
        res = min(res, solve(i+1, j+1, word1, word2, dp)); //replacing

        return dp[i][j] = 1 + res;


    }


    int minDistance(string word1, string word2) {
        
        n = word1.size(); m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(0,0, word1, word2, dp);


    }
};
