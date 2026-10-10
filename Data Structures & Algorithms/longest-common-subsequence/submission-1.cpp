class Solution {
public:

    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){

        if (i>=text1.length() || j>=text2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (text1[i] == text2[j]) dp[i][j] = 1 + solve(i+1,j+1,text1,text2, dp);

        else dp[i][j] =  max(solve(i+1, j, text1, text2, dp), solve(i,j+1,text1,text2, dp));

        return dp[i][j];

    }


    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));

        return solve(0,0,text1, text2, dp);


    }
};
