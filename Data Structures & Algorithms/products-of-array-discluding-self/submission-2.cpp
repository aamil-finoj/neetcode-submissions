class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);

        prefix[0] = 1;
        suffix[n-1] = 1;

        for (int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[n-1-i] = suffix[n-i] * nums[n-i];
        }

        ans[0] = suffix[0];
        ans[n-1] = prefix[n-1];

        for (int i=1; i<n-1; i++){
            ans[i] = prefix[i]*suffix[i];
        }

        return ans;


    }
};
