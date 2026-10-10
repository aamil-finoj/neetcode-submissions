class Solution {
public:

    int rob1(vector<int>& nums, int l, int r){

        int n = r-l+1;
        if (n==1) return nums[l];
        if (n==2) return max(nums[l], nums[l+1]);

        int prev = max(nums[l], nums[l+1]);
        int prev2 = nums[l];

        for (int i=l+2; i<=r; i++){
            int curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }

        return prev;

    }


    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];
        

        return max(rob1(nums, 0, n-2), rob1(nums, 1, n-1));


    }
};
