class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];

        int ans = nums[0];
        int prefix=0; int suffix=0;

        for (int i=0; i<n; i++){
            prefix = nums[i] * (prefix==0 ? 1: prefix);
            suffix = nums[n-1-i] * (suffix==0 ? 1 : suffix);
            ans = max(ans, max(prefix, suffix));
        }

        return ans;

    }
};
