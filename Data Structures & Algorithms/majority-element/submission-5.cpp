class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int candidate = nums[0];
        int count=0;

        for (int i=0; i<n; i++){
            if (nums[i]==candidate) count++;
            else{
                count--;
                if (count==0){candidate = nums[i]; count=1;}
            }
        }

        return candidate;


    }
};