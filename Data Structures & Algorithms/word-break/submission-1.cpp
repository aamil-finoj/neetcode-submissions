class Solution {
public:

    bool solve(int i, string& s, vector<string>& wordDict, unordered_map<int, bool>& dp){

        if (i>=s.length()) return true;

        if (dp.count(i)) return dp[i];

        bool temp = false;
        for (string word : wordDict){

            if (s.substr(i,word.length()) == word){
                temp = solve(i+word.length(), s, wordDict, dp);
                if (temp==true) break;
            }
        }

        dp[i] = temp;

        return dp[i];


    }



    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<int, bool> dp;

        return solve(0, s, wordDict, dp);

    }
};
