class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checked;

        int n = nums.size();
        for (int i=0; i<n; i++){
            int diff = target - nums[i];
            if (checked.count(diff)){
                return {checked[diff], i};
            }
            else checked[nums[i]] = i;
        }

        return{};
    }
};
