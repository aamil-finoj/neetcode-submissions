class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n-1;

        int min_idx = -1;

        while (l<r){

            int mid = l + (r-l)/2;

            if (nums[mid] > nums[r]) l=mid+1;
            else r = mid;
        }
        min_idx = l;
        int small = nums[min_idx];

        if (target<small) return -1;
        if (target >= small && target <= nums[n-1]){
            l = min_idx;
            r = n-1;
        }
        else{
            l = 0;
            r = min_idx-1;
        }

        while (l<=r){
            int mid = l + (r-l)/2;

            if (nums[mid]==target) return mid;
            else if (nums[mid]>target) r=mid-1;
            else l = mid+1;
        }

        return -1;


    }
};
