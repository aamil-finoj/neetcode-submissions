class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    
        int n = text1.size(), m = text2.size();
        if (n<m) return longestCommonSubsequence(text2,text1);

        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        

        for (int i = n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){

                if (text1[i] == text2[j]) curr[j] = 1 + prev[j+1];

                else curr[j] = max(curr[j+1], prev[j]); 


            }
            prev = curr;

        }

        return curr[0];


    }
};
