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

        int sellTmr=0, buyTmr=0, buyDayAfter=0;

        for (int i=n-1; i>=0; i--){

            int buyToday = max(buyTmr, sellTmr - prices[i]);
            int sellToday = max(sellTmr, (i<n-2 ? buyDayAfter : 0) + prices[i]);

            buyDayAfter = buyTmr;
            buyTmr = buyToday;
            sellTmr = sellToday;

        }

        return buyTmr;


    }
};
