class Solution {
private:
    int n;

public:

    int solve(vector<int>& prices, int idx, int canBuy, vector<vector<int>>& dp){
        if (idx>=n) return 0;
        if (dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if (canBuy){
            return dp[idx][canBuy] = max(solve(prices, idx+1, 1, dp), solve(prices, idx+1, 0, dp) - prices[idx]);
        }
        else{
            return dp[idx][canBuy] = max(solve(prices, idx+1, 0, dp), solve(prices, idx+1, 1, dp) + prices[idx]);
        }

        return 0;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));

        return solve(prices, 0, 1, dp);




    }
};