class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n  = prices.size();
        if (n==1) return 0;

        int buy=prices[0];
        int max_prof = 0;

        for (int i = 1; i<n; i++){
            
            buy = min(buy, prices[i-1]);
            int temp = prices[i] - buy;

            max_prof = max(max_prof, temp);

        }

        return max_prof;
        
        


    }
};
