class Solution {
public:

    // int solve(int i, vector<int>& prices, int canBuy, vector<vector<int>>& dp){

    //     if (i>=prices.size()) return 0;
    //     if (dp[i][canBuy] != -1) return dp[i][canBuy];

    //     if (canBuy){
    //         dp[i][canBuy] = max(solve(i+1, prices, 1, dp), solve(i+1, prices, 0, dp) - prices[i]);
    //     }
    //     else{
    //         dp[i][canBuy] = max(solve(i+1, prices, 0, dp), solve(i+2, prices, 1, dp) + prices[i]);
    //     }

    //     return dp[i][canBuy];
    // }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0)); //top row for selling, bottom row for buying
        // dp[0][0] = 0;
        // dp[n-1][1] = 0;
        
        for (int i=n-1; i>=0; i--){

            dp[i][1] = max(dp[i+1][1], dp[i+1][0] - prices[i]);
            dp[i][0] = max(dp[i+1][0], (i<n-2 ? dp[i+2][1] : 0) + prices[i]);

        }

        return dp[0][1];


    }
};
