class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int n = nums.size();
        int ans = 1e9;

        int curr_sum = 0;

        int l=0, r=0;
        for (r=0; r<n; r++){

            curr_sum += nums[r];
            if (curr_sum < target) continue;

            while (l<=r && curr_sum - nums[l]>=target){
                curr_sum-=nums[l]; l++;
                ans = min(ans, r-l+1);
            }

            ans = min(ans, r-l+1);

        }

        return (ans == 1e9 ? 0 : ans);


    }
};