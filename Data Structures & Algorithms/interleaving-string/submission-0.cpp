class Solution {
public:


    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp){

        if (k == s3.length()){
            return (i==s1.length() && j==s2.length());
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool res=false;
        if (i<s1.length() && s1[i] == s3[k]){
            res = solve(i+1,j,k+1,s1,s2,s3, dp);
        }
        if (res){
            dp[i][j] = res;
            return res;
        }
        if (j<s2.length() && s2[j] == s3[k]){
            res = solve(i,j+1,k+1,s1,s2,s3, dp);
        }


        return dp[i][j] = res;


    }


    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0,0,0,s1,s2,s3, dp);


    }
};
