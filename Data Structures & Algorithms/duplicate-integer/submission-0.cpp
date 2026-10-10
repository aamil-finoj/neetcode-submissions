class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freqs;
        int n = nums.size();

        for (int i=0; i<n; i++){
            if (!freqs.count(nums[i])) 
                freqs.insert(nums[i]);
            else
                return true;
        }


        return false;

    }
};