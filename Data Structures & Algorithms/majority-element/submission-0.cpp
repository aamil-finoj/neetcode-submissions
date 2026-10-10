class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqs;
        int n = nums.size();

        for (int i=0; i<n; i++){
            if (!freqs.count(nums[i])) freqs[nums[i]] = 1;
            else freqs[nums[i]]++;

            if (freqs[nums[i]] > n/2) return nums[i];
        }

        return 0;



    }
};