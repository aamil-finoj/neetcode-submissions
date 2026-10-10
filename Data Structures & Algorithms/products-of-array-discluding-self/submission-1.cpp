class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int zero_freq = 0;
        bool has_nonzero = false;
        int n = nums.size(), i;
        int final_product = 1;

        vector<int> ans(n);

        for (i=0; i<n; i++){
            if (nums[i]==0){
                zero_freq++;
            }
            else{
                has_nonzero = true;
                final_product *= nums[i];
            }
        }

        int numerator = final_product;
        if (has_nonzero == false) final_product = 0;
        if (zero_freq == 1) numerator = 0;
        if (zero_freq > 1) return vector<int>(n,0);

        for (i=0; i<n; i++){
            if (nums[i]==0) ans[i] = final_product;
            else ans[i] = numerator/nums[i];
        }

        return ans;


    }
};
