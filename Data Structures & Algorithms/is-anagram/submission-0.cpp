class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (m!=n) return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for (int i=0; i<n; i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }

        return (freq1 == freq2 ? true : false);




    }
};
