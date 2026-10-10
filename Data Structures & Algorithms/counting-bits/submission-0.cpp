class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1);

        for (int i = 1; i<=n; i++){

            int n  = i;
            int sum = 0;
            while (n!=0){
                n = n&(n-1);
                sum++;
            }
            ans[i] = sum;


        }

        return ans;

    }
};
