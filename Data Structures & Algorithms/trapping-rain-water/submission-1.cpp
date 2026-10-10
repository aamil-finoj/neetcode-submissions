class Solution {
public:
    int trap(vector<int>& height) {
        
        int total = 0;
        int n = height.size();
        int l =0, r = n-1;

        vector<int> prev(n), next(n);
        prev[0] = height[0];
        next[n-1] = height[n-1];

        for (int i=1; i<n; i++){
            prev[i] = max(prev[i-1], height[i]);
        }
        for (int i=n-2; i>=0; i--){
            next[i] = max(next[i+1], height[i]);
        }

        for (int i=0; i<n; i++){
            total+= min(prev[i], next[i])  - height[i];
        }

        return total;


    }
};
