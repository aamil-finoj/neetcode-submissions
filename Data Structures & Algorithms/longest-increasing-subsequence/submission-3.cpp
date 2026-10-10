class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        
        int max_len = 1;
        
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i]) {
                max_len = max(max_len, 1 + solve(j, nums, dp));
            }
        }
        
        return dp[i] = max_len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, -1);
        int overall_max = 1;

        for (int i = 0; i < n; i++) {
            overall_max = max(overall_max, solve(i, nums, dp));
        }

        return overall_max;
    }
};