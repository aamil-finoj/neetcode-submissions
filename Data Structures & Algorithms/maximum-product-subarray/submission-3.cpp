class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];

        int ans = nums[0];
        int currMax = 1, currMin = 1;

        for (int i=0; i<n; i++){

            int temp1 = nums[i]*currMax;
            int temp2 = nums[i]*currMin;
            currMax = max(nums[i],max(temp1, temp2));  
            currMin = min(nums[i],min(temp1, temp2));

            ans = max(ans, currMax);

        }

        return ans;


    }
};
