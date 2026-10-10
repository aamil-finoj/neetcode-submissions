class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size() ,i;
        stack<int> st_l, st_r;
        vector<int> left(n), right(n);
        

        for (i=n-1; i>=0; i--){

            if (st_r.empty()){
                right[i] = n;
                st_r.push(i);
            }

            else{
                while (!st_r.empty() && heights[i]<=heights[st_r.top()]){
                    st_r.pop();
                }
                if (st_r.empty()) right[i] = n;
                else right[i] = st_r.top();
                st_r.push(i);
            }

        }

        for (i=0; i<n; i++){

            if (st_l.empty()){
                left[i] = -1;
                st_l.push(i);
            }

            else{
                while (!st_l.empty() && heights[i]<=heights[st_l.top()]){
                    st_l.pop();
                }
                if (st_l.empty()) left[i] = -1;
                else left[i] = st_l.top();
                st_l.push(i);
            }

        }

        int ans = -1;
        for (i=0; i<n; i++){
            int curr_height = heights[i] * (right[i] - left[i] - 1);
            ans = max(ans, curr_height);
        }

        return ans;




    }
};
