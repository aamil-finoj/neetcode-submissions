class Solution {
public:

    int solve(int i, vector<int>& prices, int canBuy, vector<vector<int>>& dp){

        if (i>=prices.size()) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        if (canBuy){
            dp[i][canBuy] = max(solve(i+1, prices, 1, dp), solve(i+1, prices, 0, dp) - prices[i]);
        }
        else{
            dp[i][canBuy] = max(solve(i+1, prices, 0, dp), solve(i+2, prices, 1, dp) + prices[i]);
        }

        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return solve(0, prices, 1, dp);


    }
};
