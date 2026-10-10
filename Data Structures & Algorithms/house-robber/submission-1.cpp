class Solution {
public:

    int solve(vector<int>& nums, int i, vector<int>& dp){

        if (i<0) return 0;
        if (dp[i]!=-1) return dp[i];

        dp[i] = max(nums[i] + solve(nums, i-2, dp), solve(nums, i-1, dp));
        return dp[i];

    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0]; dp[1] = max(nums[0],nums[1]);
        return solve(nums, n-1, dp);


    }
};
