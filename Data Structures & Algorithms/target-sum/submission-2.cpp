class Solution {
public:

    int solve(int i, int total, vector<int>& nums, int target, vector<vector<int>>& dp, int totalSum){
        
        int n = nums.size();
        if (i == n) return (total==target ? 1: 0);
        if (dp[i][total+totalSum] != -1) return dp[i][total+totalSum];

        dp[i][total+totalSum] = solve(i+1, total-nums[i], nums, target, dp, totalSum) + solve(i+1, total+nums[i], nums, target, dp, totalSum);
        
        return dp[i][total+totalSum];

    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalSum = accumulate (nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(nums.size(), vector<int>(2*totalSum+1, -1));

        return solve(0,0,nums,target, dp, totalSum);


    }
};
