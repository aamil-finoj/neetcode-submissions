class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if (nums.size()==1) return nums[0];

        int candidate = nums[0];
        int val = 1;

        for (int i=1; i<nums.size(); i++){

            if (nums[i]==candidate) val++;
            else val--;

            if (val == 0) {candidate = nums[i]; val=1;}

        }

        return candidate;


    }
};