class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0, j=n-1;
        int largest = -1;

        while(i<j){

            int curr_height = (j-i)*min(heights[i], heights[j]);
            largest = max(largest, curr_height);

            if (heights[i]<heights[j]) i++;
            else j--;

        }

        return largest;



    }
};
