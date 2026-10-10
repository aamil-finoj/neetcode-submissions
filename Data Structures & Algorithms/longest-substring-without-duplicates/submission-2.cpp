class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        unordered_set<char> freq;

        if (n==0) return 0;
        if (n==1) return 1;

        int l = 0, r=1;
        int max_length = 1;

        freq.insert(s[0]);

        while (r<n){
            while (freq.count(s[r])){
                freq.erase(s[l]);
                l++;
            }
            
            freq.insert(s[r]);
            int temp = r-l+1;
            max_length = max(max_length, temp);
            r++;
        }

        return max_length;


    }
};
