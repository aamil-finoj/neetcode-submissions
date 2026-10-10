class Solution {
public:
    int characterReplacement(string s, int k) {

            int n = s.length();
            if (n==1) return 1;

            int l=0, r=0;
            int max_length = 0;
    

            unordered_map<char,int> freq;
            int maxfreq = 1;

            while (r<n){
                
                freq[s[r]]++;
                maxfreq = max(maxfreq, freq[s[r]]);

                while ((r-l+1) - maxfreq > k){
                    freq[s[l]]--;
                    l++;
                }

                max_length = max(max_length, r-l+1);
                r++;


            }   

            return max_length;

 

    }
};
