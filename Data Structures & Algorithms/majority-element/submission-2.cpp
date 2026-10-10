class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate, current;
        int n = nums.size();

        candidate = nums[0];
        current = 0;

        for (int i=0; i<n; i++){
            if (current == 0) {candidate = nums[i]; current++;}
            else if (nums[i]==candidate){
                current++;
            }
            else current--;
            
        }


        return candidate;
    }
};