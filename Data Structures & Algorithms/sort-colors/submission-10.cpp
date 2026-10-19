class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int i=0, j=0, k=n-1;

        while (j<=k){

            if (nums[k] == 2){
                k--;
                continue;
            }
            else if (nums[j]==2){
                swap(nums[j], nums[k]);
                k--;
            }
            else if (nums[j]==0){
                swap(nums[i], nums[j]);
                i++;
                j++;
                continue;
            }
            else j++;


        }

        return;
    }
};