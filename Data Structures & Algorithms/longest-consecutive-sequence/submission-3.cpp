class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int longest = 1;
        int curr_length=1;

        if (n==0) return 0;

        unordered_set<int> available;

        for (int i = 0; i<n; i++){
            if (!available.count(nums[i])) 
                available.insert(nums[i]);
        }

        for (int i=0; i<n; i++){

            if (!available.count(nums[i])) continue;
            if (available.count(nums[i]-1)) continue;
            
            int temp = nums[i];
            curr_length = 1;
            available.erase(nums[i]);

            while(1){
                if (available.count(temp+1)){
                curr_length++;
                temp++;
                available.erase(temp);
                }
                else break;
            }

            
            longest = max(curr_length, longest);

        }

        return longest;


    }
};
